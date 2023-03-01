#include "../common.h"
#include "GameClearScene.h"
#include "TitleScene.h"
#include "../KeyManager.h"


//---------------------------------
// �R���X�g���N�^
//---------------------------------
GameClearScene::GameClearScene()
{
	back = new BackScreen();
}

//---------------------------------
// �f�X�g���N�^
//---------------------------------
GameClearScene::~GameClearScene()
{
	delete back;
}

//---------------------------------
// �X�V
//---------------------------------
AbstractScene* GameClearScene::Update()
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
void GameClearScene::Draw()const
{
	back->Draw();
	int DrawWidth;

	SetFontSize(64);
	// ������̕`�敝���擾
	DrawWidth = GetDrawStringWidth("GameClear!!", -1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4 * 1, "GameClear!!", 0);

	SetFontSize(20);
	// ������̕`�敝���擾
	DrawWidth = GetDrawStringWidth("SPACE�L�[�Ń^�C�g���ɖ߂�", -1);

	// ��ʒ����ɕ`��
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACE�L�[�Ń^�C�g���ɖ߂�", 0);


}

//---------------------------------
// 
//---------------------------------
