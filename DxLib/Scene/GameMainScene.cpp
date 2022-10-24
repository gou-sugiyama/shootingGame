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
	DrawString(0, 0, "GameMainScene", 0xFFFFFF);
}

//--------------------------------
// 
//--------------------------------