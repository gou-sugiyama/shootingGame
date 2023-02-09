#include "../common.h"
#include "GameMainScene.h"
#include "GameOverScene.h"

Location default_location = { D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 2 };

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
	Location enemyLocation = { 640,0 };
	enemy[0] = new Enemy(&enemyLocation);
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
	switch (gameScene)
	{
	case D_GAMESCENE_MAIN:
		GameMainUpdate();
		break;
	case D_GAMESCENE_GAMEOVER:
		if(GameOverUpdate()) return new GameOverScene() ;
		break;
	}

	return this;
}

//--------------------------------
// ゲームメインの更新
//--------------------------------
void GameMainScene::GameMainUpdate()
{
	player->Update();
	//エネミーの更新
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}
	}


	HitCheck();
}

//--------------------------------
// ゲームオーバーの更新
//--------------------------------
bool GameMainScene::GameOverUpdate()
{
	static int timer = 120;
	timer--;
	if (timer < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
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

		//距離を測る
		Location distance = player->GetLocation() - enemy[0]->GetLocation();
		//二つのコリジョンが接したときの距離
		float range = 30;

		//距離がrange以下だったら当たってる
		distance.x = pow((double)distance.x, 2.0);
		distance.y = pow((double)distance.y, 2.0);


		DrawFormatString(0, 20 * i++, 0xFF00DD, "player y : %.1lf",(player->GetLocation()).y);
		DrawFormatString(0, 20 * i++, 0xFF00DD, "enemy[0] y : %.1lf",(enemy[0]->GetLocation()).y);
		DrawFormatString(0, 20 * i++, 0xFF00DD, "distance x : %.1lf",distance.x);
		DrawFormatString(0, 20 * i++, 0xFF00DD, "distance y : %.1lf",distance.y);

	}

}

//--------------------------------
// 当たり判定の呼び出し
//--------------------------------
void GameMainScene::HitCheck()
{
	if (HitCheck_enemy_player())
	{
		gameScene = D_GAMESCENE_GAMEOVER;
	}
}

//--------------------------------
// 敵とプレイヤーの当たり判定
//--------------------------------
bool GameMainScene::HitCheck_enemy_player()
{
	bool isHit = false;
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		//エネミーは正常か
		if (enemy[i] != nullptr)
		{
			//当たっているか
			if (player->HitSphere(enemy[i]))
			{
				isHit = true;
			}
			if (enemy[i]->HitSphere(player))
			{
				isHit = true;
			}
		}
	}

	return isHit;
}

//--------------------------------
// 
//--------------------------------