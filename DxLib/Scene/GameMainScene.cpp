#include "../common.h"
#include "GameMainScene.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
GameMainScene::GameMainScene()
{
	player = new Player();
}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
}

//--------------------------------
// �X�V
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	player->Update();

	return this;
}

//--------------------------------
// �`��
//--------------------------------
void GameMainScene::Draw()const
{
	player->Draw();

	//�f�o�b�O�p�u���b�N
	{
		int i = 0;
		DrawString(0, 20 * i++, "GameMainScene", 0xFFFFFF);

	}

}

//--------------------------------
// 
//--------------------------------