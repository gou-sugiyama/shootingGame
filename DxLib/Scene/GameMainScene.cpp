#include "../common.h"
#include "GameMainScene.h"

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
	Location enemyLocation = { D_SCREEN_SIZE_X / 2,0 };
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
	player->Update();
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}
	}

	HitCheck();

	return this;
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
		DrawString(0, 20 * i++, "GameMainScene", 0xFFFFFF);
		if (debug)
		{
			DrawFormatString(0, 20 * i++, 0xFF00DD, "debug : TRUE");
		}
		else
		{
			DrawFormatString(0, 20 * i++, 0xFF00DD, "debug : FALSE" );
		}

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
	debug = HitCheck_enemy_player();
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
				//isHit = true;
			}
		}
	}

	return isHit;
}

//--------------------------------
// 
//--------------------------------