#include "DxLib.h"
#include "GameMainScene.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
GameMainScene::GameMainScene()
{
	;
}


//--------------------------------
// �X�V
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	return this;
}

//--------------------------------
// �`��
//--------------------------------
void GameMainScene::Draw()const
{
	DrawString(0, 0, "GameMainScene", 0xFFFFFF);
}

//--------------------------------
// 
//--------------------------------