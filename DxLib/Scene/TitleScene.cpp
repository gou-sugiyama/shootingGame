#include "../common.h"
#include "TitleScene.h"

//-------------------------------
// �R���X�g���N�^
//-------------------------------
TitleScene::TitleScene()
{
	;
}

//----------------------------------
// �X�V
//----------------------------------
AbstractScene* TitleScene::Update()
{
	return this;
}

//----------------------------------
// �`��
//----------------------------------
void TitleScene::Draw()const 
{
	DrawString(0, 0, "TitleScene", 0xFFFFFF);
}