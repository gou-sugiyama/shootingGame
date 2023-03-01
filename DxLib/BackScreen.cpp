#include "BackScreen.h"
#include "common.h"

//---------------------------------
// コンストラクタ
//---------------------------------
BackScreen::BackScreen()
{
	image = LoadGraph("images/back.png");
	scrollY = 0;
	scrollTime = 0;
}

//---------------------------------
// デストラクタ
//---------------------------------
BackScreen::~BackScreen()
{

}

//---------------------------------
// 更新
//---------------------------------
void BackScreen::Update()
{
	scrollTime++;
	if (scrollTime % 30 == 0)
	{
		scrollY -= BACK_SCREEN_IMAGE_HEIGHT / 4;
		//スクロール時、画面下に
		if (BACK_SCREEN_IMAGE_HEIGHT - D_SCREEN_SIZE_Y > BACK_SCREEN_IMAGE_HEIGHT + scrollY)
		{
			scrollY = 0;
		}
	}
}

//---------------------------------
// 描画
//---------------------------------
void BackScreen::Draw()const
{
	DrawGraph(0, scrollY, image, FALSE);
}

//---------------------------------
// 
//---------------------------------
