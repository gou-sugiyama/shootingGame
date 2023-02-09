#include "../common.h"
#include "GameMainScene.h"
#include "GameOverScene.h"

Location default_location = { D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 2 };

//--------------------------------
// �R���X�g���N�^
//--------------------------------
GameMainScene::GameMainScene()
{
	player = new Player();
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		enemy[i] = nullptr;
	}
	
	//�f�o�b�O�p
	Location enemyLocation = { 640,0 };
	enemy[0] = new Enemy(&enemyLocation);
}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		delete enemy[i];
	}
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
	for (int i = 0; i < D_ENEMY_MAX; i++)
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
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}


	//�f�o�b�O�p�u���b�N
	{
		int i = 0;

		//�����𑪂�
		Location distance = player->GetLocation() - enemy[0]->GetLocation();
		//��̃R���W�������ڂ����Ƃ��̋���
		float range = 30;

		//������range�ȉ��������瓖�����Ă�
		distance.x = pow((double)distance.x, 2.0);
		distance.y = pow((double)distance.y, 2.0);


		DrawFormatString(0, 20 * i++, 0xFF00DD, "player y : %.1lf",(player->GetLocation()).y);
		DrawFormatString(0, 20 * i++, 0xFF00DD, "enemy[0] y : %.1lf",(enemy[0]->GetLocation()).y);
		DrawFormatString(0, 20 * i++, 0xFF00DD, "distance x : %.1lf",distance.x);
		DrawFormatString(0, 20 * i++, 0xFF00DD, "distance y : %.1lf",distance.y);

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
}

//--------------------------------
// �G�ƃv���C���[�̓����蔻��
//--------------------------------
bool GameMainScene::HitCheck_enemy_player()
{
	bool isHit = false;
	for (int i = 0; i < D_ENEMY_MAX; i++)
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
// 
//--------------------------------