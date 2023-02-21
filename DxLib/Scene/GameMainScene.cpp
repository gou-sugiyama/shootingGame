#include "../common.h"
#include "GameMainScene.h"
#include "GameOverScene.h"

Location default_location = { D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 2 };

//--------------------------------
// コンストラクタ
//--------------------------------
GameMainScene::GameMainScene()
{
	BulletsManager::Create();
	player = new Player();
	
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		Location location = { 200 + 100 * i,0 };
		enemy.push_back(new Enemy(location));
	}
}

//--------------------------------
// デストラクタ
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
	for (int i = 0; i < enemy.size(); i++)
	{
		delete enemy[i];
		enemy.clear();
	}
	BulletsManager::Delete();
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
	for (int i = 0; i < enemy.size(); i++)
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
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}


	//デバッグ用ブロック
	{
		int i = 0;


		DrawFormatString(0, 20 * i++, 0xFF00DD, "player y : %.1lf",(player->GetLocation()).y);
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

	for (int i = 0; i < enemy.size(); i++)
	{
		if (HitCheck_chara_bullet(enemy[i], player))
		{
			delete enemy[i];
			enemy.erase(enemy.begin() + i);
		}
	}
}

//--------------------------------
// 敵とプレイヤーの当たり判定
//--------------------------------
bool GameMainScene::HitCheck_enemy_player()
{
	bool isHit = false;
	for (int i = 0; i < enemy.size(); i++)
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
// キャラと弾の当たり判定
//--------------------------------
bool GameMainScene::HitCheck_chara_bullet(CharaBase* character, CharaBase* Bullets)
{
	return false;
}