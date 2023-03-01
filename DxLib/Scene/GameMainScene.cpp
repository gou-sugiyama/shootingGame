#include "../common.h"
#include "GameMainScene.h"
#include "GameOverScene.h"
#include "GameClearScene.h"

Location default_location = { D_SCREEN_SIZE_X / 2,D_SCREEN_SIZE_Y / 2 };

//--------------------------------
// コンストラクタ
//--------------------------------
GameMainScene::GameMainScene()
{
	BulletsManager::Create();
	bulletsManager = BulletsManager::GetInstance();
	EnemyManager::Create();
	enemyManager = EnemyManager::GetInstance();

	player = new Player();
	back = new BackScreen();
	
	enemy = enemyManager->GetEnemyInstance();
	
	for(int i= 0;i<10;i++)
	{
		Location location = { 200.f + 100.f * i,0 };
		enemyManager->EnemySpawns(location);
	}

}

//--------------------------------
// デストラクタ
//--------------------------------
GameMainScene::~GameMainScene()
{
	delete player;
	delete back;

	BulletsManager::Delete();
	EnemyManager::Delete();

	for (int i = 0; i < item.size(); i++)
	{
		delete item[i];
	}
	item.clear();

}

//--------------------------------
// 更新
//--------------------------------
AbstractScene* GameMainScene::Update()
{
	bulletsManager->Update();
	back->Update();
	if (enemyManager->GetDestroyed() >= 10)
	{
		gameScene = GAMESCENE_GAMECLEAR;
		enemyManager->InitDestroyed();
	}
	
	//アイテムの更新と削除
	for (int i = 0; i < item.size(); i++)
	{
		item[i]->Update();
		if (item[i]->isScreenOut())
		{
			delete item[i];
			item.erase(item.begin() + i);
		}
	}

	switch (gameScene)
	{
	case GAMESCENE_MAIN:
		GameMainUpdate();
		break;
	case GAMESCENE_GAMEOVER:
		if(GameOverUpdate()) return new GameOverScene() ;
		break;
	case GAMESCENE_GAMECLEAR:
		return new GameClearScene() ;
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
	for (int i = 0; i < enemy->size(); i++)
	{
		if ((*enemy)[i] != nullptr)
		{
			(*enemy)[i]->Update();
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
		//2秒たった
		return true;
	}
	else
	{
		//2秒たってない
		return false;
	}
}

//--------------------------------
// 描画
//--------------------------------
void GameMainScene::Draw()const
{
	back->Draw();
	bulletsManager->Draw();
	player->Draw();
	for (int i = 0; i < enemy->size(); i++)
	{
		if ((*enemy)[i] != nullptr)
		{
			(*enemy)[i]->Draw();
		}
	}

	for (int i = 0; i < item.size(); i++)
	{
		item[i]->Draw();
	}

}

//--------------------------------
// 当たり判定の呼び出し
//--------------------------------
void GameMainScene::HitCheck()
{
	HitCheck_player_bullet();
	HitCheck_enemy_bullet();
	if (player->LifeCheck() == false)
	{
		gameScene = GAMESCENE_GAMEOVER;
	}
	player->GetScore(enemyManager->EnemyDies());
}

//--------------------------------
// 敵とプレイヤーの当たり判定
//--------------------------------
bool GameMainScene::HitCheck_enemy_player()
{
	bool isHit = false;
	for (int i = 0; i < enemy->size(); i++)
	{
		//エネミーは正常か
		if ((*enemy)[i] != nullptr)
		{
			//当たっているか
			if (player->HitSphere((*enemy)[i]))
			{
				isHit = true;
			}
			if ((*enemy)[i]->HitSphere(player))
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
		auto it = bulletsManager->at(ENEMY_BULLETS, i);
		if (player->HitSphere(it))
		{
			player->ReceiveDamage(it->GetDamage());
			isHit = true;
			bulletsManager->Hit(ENEMY_BULLETS, i);
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
	for (int i = 0; i < enemy->size(); i++)
	{
		for (int j = 0; j < bulletsManager->size(PLAYER_BULLETS); j++)
		{
			auto it = bulletsManager->at(PLAYER_BULLETS, j);
			if ((*enemy)[i]->HitSphere(it))
			{
				(*enemy)[i]->ReceiveDamage(it->GetDamage());
				if ((*enemy)[i]->HpCheck() == false)
				{
					//20％の確率で生成する
					if (!GetRand(4))item.push_back(new Item((*enemy)[i]->GetLocation(), 0));
				}
				isHit = true;
				bulletsManager->Hit(PLAYER_BULLETS, j);
			}
		}
	}

	return isHit;
}