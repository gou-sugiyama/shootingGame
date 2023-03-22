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
	
	enemyManager->GetPlayerInstance(player);
	enemy = enemyManager->GetEnemyInstance();

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

	switch (gameScene)
	{
	case GAMESCENE_MAIN:
		GameMainUpdate();
		break;
	case GAMESCENE_GAMEOVER:
		if (TransitionTime()) return new GameOverScene(player->GetScore());
		break;
	case GAMESCENE_GAMECLEAR:
		if (TransitionTime()) return new GameClearScene(player->GetScore());
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

	if (enemyManager->Update())
	{
		gameScene = GAMESCENE_GAMECLEAR;
	}


	HitCheck();
}

//--------------------------------
// �Q�[���I�[�o�[�̍X�V
//--------------------------------
bool GameMainScene::TransitionTime()
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
	player->Draw();
	bulletsManager->Draw();
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
	HitCheck_item();
	if (player->LifeCheck() == false)
	{
		gameScene = GAMESCENE_GAMEOVER;
	}
	player->GetScore(enemyManager->EnemyDies());
}

//--------------------------------
// �G�ƃv���C���[�̓����蔻��
//--------------------------------
void GameMainScene::HitCheck_enemy_player()
{
	for (int i = 0; i < enemy->size(); i++)
	{
		//�G�l�~�[�͐��킩
		if ((*enemy)[i] != nullptr)
		{
			//�������Ă��邩
			if (player->HitSphere((*enemy)[i]))
			{

			}
		}
	}

}

//--------------------------------
// �v���C���[�ƒe�̓����蔻��
//--------------------------------
void GameMainScene::HitCheck_player_bullet()
{
	for (int i = 0; i < bulletsManager->size(ENEMY_BULLETS); i++)
	{
		auto it = bulletsManager->at(ENEMY_BULLETS, i);
		if (player->HitSphere(it))
		{
			player->ReceiveDamage(it->GetDamage());
			bulletsManager->Hit(ENEMY_BULLETS, i);
		}
	}
}

//--------------------------------
// �G�ƒe�̓����蔻��
//--------------------------------
void GameMainScene::HitCheck_enemy_bullet()
{
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
					//30���̊m���Ő�������aa
					if (GetRand(99) <= 29)item.push_back(new Item((*enemy)[i]->GetLocation(), 0));
				}
				bulletsManager->Hit(PLAYER_BULLETS, j);
			}
		}
	}
}

//---------------------------------
// �A�C�e���Ƃ̓����蔻��
//---------------------------------
void GameMainScene::HitCheck_item()
{
	for (int i = 0; i < item.size(); i++)
	{
		if (player->HitSphere(item[i]))
		{
			item[i]->GetEffect(player);
			delete item[i];
			item.erase(item.begin() + i);
		}
	}
}