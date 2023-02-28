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
	bulletsManager = BulletsManager::GetInstance();

	player = new Player();
	
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		Location location = { 200.f + 100.f * i,0 };
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
	bulletsManager->Update();

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

	bulletsManager->size(0);
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
	bulletsManager->Draw();
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
	HitCheck_player_bullet();
	HitCheck_enemy_bullet();
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
// プレイヤーと弾の当たり判定
//--------------------------------
bool GameMainScene::HitCheck_player_bullet()
{
	bool isHit = false;
	for (int i = 0; i < bulletsManager->size(ENEMY_BULLETS); i++)
	{
		if (player->HitSphere(bulletsManager->at(ENEMY_BULLETS, i)))
		{
			bulletsManager->Hit(ENEMY_BULLETS, i);
			
			isHit = true;
		}
	}
	return isHit;
}

//--------------------------------
// 敵と弾の当たり判定
//--------------------------------
bool GameMainScene::HitCheck_enemy_bullet()
{
	bool isHit = false;
	for (int i = 0; i < enemy.size(); i++)
	{
		for (int j = 0; j < bulletsManager->size(PLAYER_BULLETS); j++)
		{
			if (enemy[i]->HitSphere(bulletsManager->at(PLAYER_BULLETS, j)))
			{
				bulletsManager->Hit(PLAYER_BULLETS, j);
				isHit = true;
			}
		}
	}

	return isHit;
}