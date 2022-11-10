#include "DxLib.h"
#include "GameMainScene.h"

//--------------------------------
// コンストラクタ
//--------------------------------
GameMainScene::GameMainScene()
{
	;
}


//--------------------------------
// 更新
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	return this;
}

//--------------------------------
// 描画
//--------------------------------
void GameMainScene::Draw()const
{
	//デバッグ用ブロック
	{
		int i = 0;
		DrawString(0, 20*i++, "GameMainScene", 0xFFFFFF);

	}

}

//--------------------------------
// 
//--------------------------------