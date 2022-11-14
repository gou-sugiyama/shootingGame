#include "../common.h"
#include "GameMainScene.h"

//--------------------------------
// コンストラクタ
//--------------------------------
GameMainScene::GameMainScene()
{
	player = new Player();
}

//--------------------------------
// デストラクタ
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
}

//--------------------------------
// 更新
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	player->Update();

	return this;
}

//--------------------------------
// 描画
//--------------------------------
void GameMainScene::Draw()const
{
	player->Draw();

	//デバッグ用ブロック
	{
		int i = 0;
		DrawString(0, 20 * i++, "GameMainScene", 0xFFFFFF);

	}

}

//--------------------------------
// 
//--------------------------------