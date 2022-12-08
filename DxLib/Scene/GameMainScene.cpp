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
	Location enemyLocation = { D_SCREEN_SIZE_X / 2,0 };
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
	player->Update();
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update();
		}
	}

	HitCheck();

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
		if (debug)
		{
			DrawFormatString(0, 20 * i++, 0xFF00DD, "debug : TRUE");
		}
		else
		{
			DrawFormatString(0, 20 * i++, 0xFF00DD, "debug : FALSE" );
		}

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
	debug = HitCheck_enemy_player();
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
				//isHit = true;
			}
		}
	}

	return isHit;
}

//--------------------------------
// 
//--------------------------------