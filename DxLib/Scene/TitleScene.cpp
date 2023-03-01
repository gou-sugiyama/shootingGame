#include "../common.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "../KeyManager.h"

//-------------------------------
// コンストラクタ
//-------------------------------
TitleScene::TitleScene()
{
	back = new BackScreen();
}

//----------------------------------
// 更新
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
// 描画
//----------------------------------
void TitleScene::Draw()const 
{
	back->Draw();
	SetFontSize(64);
	int DrawWidth = GetDrawStringWidth("しゅーてぃんぐげーむ",-1);
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4 , "しゅーてぃんぐげーむ", 0);

	SetFontSize(20);
	// 文字列の描画幅を取得
	DrawWidth = GetDrawStringWidth("SPACEキーでゲームスタート",-1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACEキーでゲームスタート", 0);

}