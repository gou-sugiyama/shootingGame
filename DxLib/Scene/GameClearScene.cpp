#include "../common.h"
#include "GameClearScene.h"
#include "TitleScene.h"
#include "../KeyManager.h"


//---------------------------------
// コンストラクタ
//---------------------------------
GameClearScene::GameClearScene()
{
	back = new BackScreen();
}

//---------------------------------
// デストラクタ
//---------------------------------
GameClearScene::~GameClearScene()
{
	delete back;
}

//---------------------------------
// 更新
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
// 描画
//---------------------------------
void GameClearScene::Draw()const
{
	back->Draw();
	int DrawWidth;

	SetFontSize(64);
	// 文字列の描画幅を取得
	DrawWidth = GetDrawStringWidth("GameClear!!", -1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 4 * 1, "GameClear!!", 0);

	SetFontSize(20);
	// 文字列の描画幅を取得
	DrawWidth = GetDrawStringWidth("SPACEキーでタイトルに戻る", -1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACEキーでタイトルに戻る", 0);


}

//---------------------------------
// 
//---------------------------------
