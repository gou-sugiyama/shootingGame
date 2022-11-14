#include "../common.h"
#include "GameMainScene.h"

//--------------------------------
// コンストラクタ
//--------------------------------
GameMainScene::GameMainScene()
{
	player = new Player();
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		enemy[i] = nullptr;
	}
	


	//デバッグ用
	enemy[0] = new Enemy();
}

//--------------------------------
// デストラクタ
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		delete enemy[i];
	}
}

//--------------------------------
// 更新
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	player->Update();
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}
	}

	return this;
}

//--------------------------------
// 描画
//--------------------------------
void GameMainScene::Draw()const
{
	player->Draw();
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//デバッグ用ブロック
	{
		int i = 0;
		DrawString(0, 20 * i++, "GameMainScene", 0xFFFFFF);

	}

}

//--------------------------------
// 
//--------------------------------