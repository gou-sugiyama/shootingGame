#include "../common.h"
#include "TitleScene.h"

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
	return this;
}

//----------------------------------
// 描画
//----------------------------------
void TitleScene::Draw()const 
{
	DrawString(0, 0, "TitleScene", 0xFFFFFF);
}