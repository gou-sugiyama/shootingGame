#include "../common.h"
#include "GameOverScene.h"
#include "TitleScene.h"
#include "../KeyManager.h"

//---------------------------------
// �R���X�g���N�^
//---------------------------------
GameOverScene::GameOverScene()
{

}

//---------------------------------
// �f�X�g���N�^
//---------------------------------
GameOverScene::~GameOverScene()
{

}

//---------------------------------
// �X�V
//---------------------------------
AbstractScene* GameOverScene::Update()
{

	if (KeyManager::OnKeyClicked(KEY_INPUT_SPACE))
	{
		return new TitleScene();
	}
	else
	{
		return this;
	}
}

//---------------------------------
// �`��
//---------------------------------
void GameOverScene::Draw()const
{
	int DrawWidth;
	DrawString(0, 0, "GameOverScene", 0xFFFFFF);

	SetFontSize(64);
	// ������̕`�敝���擾
	DrawWidth = GetDrawStringWidth("GameOver", -1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4 * 1, "GameOver", GetColor(255, 255, 255));

	SetFontSize(20);
	// ������̕`�敝���擾
	DrawWidth = GetDrawStringWidth("SPACE�L�[�Ń^�C�g���ɖ߂�", -1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACE�L�[�Ń^�C�g���ɖ߂�", GetColor(255, 255, 255));

}

//---------------------------------
// 
//---------------------------------
