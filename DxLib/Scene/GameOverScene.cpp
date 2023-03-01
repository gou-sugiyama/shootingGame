#include "../common.h"
#include "GameOverScene.h"
#include "TitleScene.h"
#include "../KeyManager.h"

//---------------------------------
// コンストラクタ
//---------------------------------
GameOverScene::GameOverScene()
{
	back = new BackScreen();
}

//---------------------------------
// デストラクタ
//---------------------------------
GameOverScene::~GameOverScene()
{
	delete back;
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

	back->Draw();
	SetFontSize(64);
	DrawWidth = GetDrawStringWidth("GameOver", -1);
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4, "GameOver", 0);

	SetFontSize(20);
	// 文字列の描画幅を取得
	DrawWidth = GetDrawStringWidth("SPACEキーでタイトルに戻る", -1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACEキーでタイトルに戻る", 0);

}

//---------------------------------
// 
//---------------------------------
