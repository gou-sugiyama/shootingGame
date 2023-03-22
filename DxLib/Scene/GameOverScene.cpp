#include "../common.h"
#include "GameOverScene.h"
#include "TitleScene.h"
#include "../KeyManager.h"

//---------------------------------
// �R���X�g���N�^
//---------------------------------
GameOverScene::GameOverScene(int score)
{
	this->score = score;
	back = new BackScreen();
}

//---------------------------------
// �f�X�g���N�^
//---------------------------------
GameOverScene::~GameOverScene()
{
	delete back;
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

	back->Draw();
	SetFontSize(64);
	DrawWidth = GetDrawStringWidth("GameOver", -1);
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4, "GameOver", 0);

	SetFontSize(20);

	DrawWidth = GetDrawStringWidth("Your score : 0000000", -1);
	DrawFormatString((D_SCREEN_SIZE_X - DrawWidth) / 2,
		D_SCREEN_SIZE_Y / 2, 0, "Your Score %7d", score);

	// ������̕`�敝���擾
	DrawWidth = GetDrawStringWidth("SPACE�L�[�Ń^�C�g���ɖ߂�", -1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACE�L�[�Ń^�C�g���ɖ߂�", 0);

}

//---------------------------------
// 
//---------------------------------
