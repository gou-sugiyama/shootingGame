#include "../common.h"
#include "GameOverScene.h"
#include "TitleScene.h"
#include "../KeyManager.h"

//---------------------------------
// コンストラクタ
//---------------------------------
GameOverScene::GameOverScene()
{

}

//---------------------------------
// デストラクタ
//---------------------------------
GameOverScene::~GameOverScene()
{

}

//---------------------------------
// 更新
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
// 描画
//---------------------------------
void GameOverScene::Draw()const
{
	int DrawWidth;
	DrawString(0, 0, "GameOverScene", 0xFFFFFF);

	SetFontSize(64);
	// 文字列の描画幅を取得
	DrawWidth = GetDrawStringWidth("GameOver", -1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4 * 1, "GameOver", GetColor(255, 255, 255));

	SetFontSize(20);
	// 文字列の描画幅を取得
	DrawWidth = GetDrawStringWidth("SPACEキーでタイトルに戻る", -1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACEキーでタイトルに戻る", GetColor(255, 255, 255));

}

//---------------------------------
// 
//---------------------------------
