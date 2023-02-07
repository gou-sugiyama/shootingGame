#include "../common.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "../KeyManager.h"

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
	DrawString(0, 0, "TitleScene", 0xFFFFFF);


	// ������̕`�敝���擾
	int DrawWidth = GetDrawStringWidth("SPACE�L�[�ŃQ�[���X�^�[�g",-1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACE�L�[�ŃQ�[���X�^�[�g", GetColor(255, 255, 255));

}