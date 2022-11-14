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
	enemy[0] = new Enemy();
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

	}

}

//--------------------------------
// 
//--------------------------------