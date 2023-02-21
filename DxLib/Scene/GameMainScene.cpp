#include "../common.h"
#include "GameMainScene.h"
#include "GameOverScene.h"

Location default_location = { D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 2 };

//--------------------------------
// �R���X�g���N�^
//--------------------------------
GameMainScene::GameMainScene()
{
	BulletsManager::Create();
	player = new Player();
	
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		Location location = { 200 + 100 * i,0 };
		enemy.push_back(new Enemy(location));
	}
}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
	for (int i = 0; i < enemy.size(); i++)
	{
		delete enemy[i];
		enemy.clear();
	}
	BulletsManager::Delete();
}

//--------------------------------
// �X�V
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	switch (gameScene)
	{
	case D_GAMESCENE_MAIN:
		GameMainUpdate();
		break;
	case D_GAMESCENE_GAMEOVER:
		if(GameOverUpdate()) return new GameOverScene() ;
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
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
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
		return true;
	}
	else
	{
		return false;
	}
}

//--------------------------------
// �`��
//--------------------------------
void GameMainScene::Draw()const
{
	player->Draw();
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}


	//�f�o�b�O�p�u���b�N
	{
		int i = 0;


		DrawFormatString(0, 20 * i++, 0xFF00DD, "player y : %.1lf",(player->GetLocation()).y);
	}

}

//--------------------------------
// �����蔻��̌Ăяo��
//--------------------------------
void GameMainScene::HitCheck()
{
	if (HitCheck_enemy_player())
	{
		gameScene = D_GAMESCENE_GAMEOVER;
	}

	for (int i = 0; i < enemy.size(); i++)
	{
		if (HitCheck_chara_bullet(enemy[i], player))
		{
			delete enemy[i];
			enemy.erase(enemy.begin() + i);
		}
	}
}

//--------------------------------
// �G�ƃv���C���[�̓����蔻��
//--------------------------------
bool GameMainScene::HitCheck_enemy_player()
{
	bool isHit = false;
	for (int i = 0; i < enemy.size(); i++)
	{
		//�G�l�~�[�͐��킩
		if (enemy[i] != nullptr)
		{
			//�������Ă��邩
			if (player->HitSphere(enemy[i]))
			{
				isHit = true;
			}
			if (enemy[i]->HitSphere(player))
			{
				isHit = true;
			}
		}
	}

	return isHit;
}

//--------------------------------
// �L�����ƒe�̓����蔻��
//--------------------------------
bool GameMainScene::HitCheck_chara_bullet(CharaBase* character, CharaBase* Bullets)
{
	return false;
}