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
	//�f�o�b�O�p�u���b�N
	{
		int i = 0;
		DrawString(0, 20*i++, "GameMainScene", 0xFFFFFF);

	}

}

//--------------------------------
// 
//--------------------------------