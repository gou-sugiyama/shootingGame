#include "BackScreen.h"
#include "common.h"

//---------------------------------
// �R���X�g���N�^
//---------------------------------
BackScreen::BackScreen()
{
	image = LoadGraph("images/back.png");
	scrollY = 0;
	scrollTime = 0;
}

//---------------------------------
// �f�X�g���N�^
//---------------------------------
BackScreen::~BackScreen()
{

}

//---------------------------------
// �X�V
//---------------------------------
void BackScreen::Update()
{
	scrollTime++;
	if (scrollTime % 30 == 0)
	{
		scrollY -= BACK_SCREEN_IMAGE_HEIGHT / 4;
		//�X�N���[�����A��ʉ���
		if (BACK_SCREEN_IMAGE_HEIGHT - D_SCREEN_SIZE_Y > BACK_SCREEN_IMAGE_HEIGHT + scrollY)
		{
			scrollY = 0;
		}
	}
}

//---------------------------------
// �`��
//---------------------------------
void BackScreen::Draw()const
{
	DrawGraph(0, scrollY, image, FALSE);
}

//---------------------------------
// 
//---------------------------------
