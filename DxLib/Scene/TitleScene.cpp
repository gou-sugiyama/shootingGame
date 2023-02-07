#include "../common.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "../KeyManager.h"

//-------------------------------
// コンストラクタ
//-------------------------------
TitleScene::TitleScene()
{
	;
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
	DrawString(0, 0, "TitleScene", 0xFFFFFF);


	// 文字列の描画幅を取得
	int DrawWidth = GetDrawStringWidth("SPACEキーでゲームスタート",-1);

	// 画面中央に描画
	DrawString((D_SCREEN_SIZE_X - DrawWidth) / 2, D_SCREEN_SIZE_Y / 3 * 2, "SPACEキーでゲームスタート", GetColor(255, 255, 255));

}