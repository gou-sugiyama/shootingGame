#include "../common.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "../KeyManager.h"

//-------------------------------
// �R���X�g���N�^
//-------------------------------
TitleScene::TitleScene()
{
	back = new BackScreen();
}

//----------------------------------
// �X�V
//----------------------------------
AbstractScene* TitleScene::Update()
{
	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE))
	{
		return new GameMainScene();
	}
	else
	{
		return this;
	}
}

//----------------------------------
// �`��
//----------------------------------
void TitleScene::Draw()const 
{
	back->Draw();
	SetFontSize(64);
	int DrawWidth = GetDrawStringWidth("����[�Ă��񂮂��[��",-1);
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4 , "����[�Ă��񂮂��[��", 0);

	SetFontSize(20);
	// ������̕`�敝���擾
	DrawWidth = GetDrawStringWidth("SPACE�L�[�ŃQ�[���X�^�[�g",-1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACE�L�[�ŃQ�[���X�^�[�g", 0);

}