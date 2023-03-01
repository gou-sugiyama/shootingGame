#include "../common.h"
#include "GameMainScene.h"
#include "GameOverScene.h"
#include "GameClearScene.h"

Location default_location = { D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 2 };

//--------------------------------
// �R���X�g���N�^
//--------------------------------
GameMainScene::GameMainScene()
{
	BulletsManager::Create();
	bulletsManager = BulletsManager::GetInstance();
	EnemyManager::Create();
	enemyManager = EnemyManager::GetInstance();

	player = new Player();
	back = new BackScreen();
	
	enemy = enemyManager->GetEnemyInstance();
	
	for(int i= 0;i<10;i++)
	{
		Location location = { 200.f + 100.f * i,0 };
		enemyManager->EnemySpawns(location);
	}

}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
	delete back;

	BulletsManager::Delete();
	EnemyManager::Delete();

	for (int i = 0; i < item.size(); i++)
	{
		delete item[i];
	}
	item.clear();

}

//--------------------------------
// �X�V
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	bulletsManager->Update();
	back->Update();
	if (enemyManager->GetDestroyed() >= 10)
	{
		gameScene = GAMESCENE_GAMECLEAR;
		enemyManager->InitDestroyed();
	}
	
	//�A�C�e���̍X�V�ƍ폜
	for (int i = 0; i < item.size(); i++)
	{
		item[i]->Update();
		if (item[i]->isScreenOut())
		{
			delete item[i];
			item.erase(item.begin() + i);
		}
	}

	switch (gameScene)
	{
	case GAMESCENE_MAIN:
		GameMainUpdate();
		break;
	case GAMESCENE_GAMEOVER:
		if(GameOverUpdate()) return new GameOverScene() ;
		break;
	case GAMESCENE_GAMECLEAR:
		return new GameClearScene() ;
		break;
	}

	return this;
}

//--------------------------------
// �Q�[�����C���̍X�V
//--------------------------------
void GameMainScene::GameMainUpdate()
{
	player->Update();
	//�G�l�~�[�̍X�V
	for (int i = 0; i < enemy->size(); i++)
	{
		if ((*enemy)[i] != nullptr)
		{
			(*enemy)[i]->Update();
		}
	}

	HitCheck();
}

//--------------------------------
// �Q�[���I�[�o�[�̍X�V
//--------------------------------
bool GameMainScene::GameOverUpdate()
{
	static int timer = 120;
	timer--;
	if (timer < 0)
	{
		//2�b������
		return true;
	}
	else
	{
		//2�b�����ĂȂ�
		return false;
	}
}

//--------------------------------
// �`��
//--------------------------------
void GameMainScene::Draw()const
{
	back->Draw();
	bulletsManager->Draw();
	player->Draw();
	for (int i = 0; i < enemy->size(); i++)
	{
		if ((*enemy)[i] != nullptr)
		{
			(*enemy)[i]->Draw();
		}
	}

	for (int i = 0; i < item.size(); i++)
	{
		item[i]->Draw();
	}

}

//--------------------------------
// �����蔻��̌Ăяo��
//--------------------------------
void GameMainScene::HitCheck()
{
	HitCheck_player_bullet();
	HitCheck_enemy_bullet();
	if (player->LifeCheck() == false)
	{
		gameScene = GAMESCENE_GAMEOVER;
	}
	player->GetScore(enemyManager->EnemyDies());
}

//--------------------------------
// �G�ƃv���C���[�̓����蔻��
//--------------------------------
bool GameMainScene::HitCheck_enemy_player()
{
	bool isHit = false;
	for (int i = 0; i < enemy->size(); i++)
	{
		//�G�l�~�[�͐��킩
		if ((*enemy)[i] != nullptr)
		{
			//�������Ă��邩
			if (player->HitSphere((*enemy)[i]))
			{
				isHit = true;
			}
			if ((*enemy)[i]->HitSphere(player))
			{
				isHit = true;
			}
		}
	}

	return isHit;
}

//--------------------------------
// �v���C���[�ƒe�̓����蔻��
//--------------------------------
bool GameMainScene::HitCheck_player_bullet()
{
	bool isHit = false;
	for (int i = 0; i < bulletsManager->size(ENEMY_BULLETS); i++)
	{
		auto it = bulletsManager->at(ENEMY_BULLETS, i);
		if (player->HitSphere(it))
		{
			player->ReceiveDamage(it->GetDamage());
			isHit = true;
			bulletsManager->Hit(ENEMY_BULLETS, i);
		}
	}
	return isHit;
}

//--------------------------------
// �G�ƒe�̓����蔻��
//--------------------------------
bool GameMainScene::HitCheck_enemy_bullet()
{
	bool isHit = false;
	for (int i = 0; i < enemy->size(); i++)
	{
		for (int j = 0; j < bulletsManager->size(PLAYER_BULLETS); j++)
		{
			auto it = bulletsManager->at(PLAYER_BULLETS, j);
			if ((*enemy)[i]->HitSphere(it))
			{
				(*enemy)[i]->ReceiveDamage(it->GetDamage());
				if ((*enemy)[i]->HpCheck() == false)
				{
					//20���̊m���Ő�������
					if (!GetRand(4))item.push_back(new Item((*enemy)[i]->GetLocation(), 0));
				}
				isHit = true;
				bulletsManager->Hit(PLAYER_BULLETS, j);
			}
		}
	}

	return isHit;
}