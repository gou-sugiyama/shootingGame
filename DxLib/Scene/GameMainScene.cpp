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
	
	enemyManager->GetPlayerInstance(player);
	enemy = enemyManager->GetEnemyInstance();

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

	switch (gameScene)
	{
	case GAMESCENE_MAIN:
		GameMainUpdate();
		break;
	case GAMESCENE_GAMEOVER:
		if (TransitionTime()) return new GameOverScene(player->GetScore());
		break;
	case GAMESCENE_GAMECLEAR:
		if (TransitionTime()) return new GameClearScene(player->GetScore());
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

	if (enemyManager->Update())
	{
		gameScene = GAMESCENE_GAMECLEAR;
	}


	HitCheck();
}

//--------------------------------
// ゲームオーバーの更新
//--------------------------------
bool GameMainScene::TransitionTime()
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
	player->Draw();
	bulletsManager->Draw();
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
	HitCheck_item();
	if (player->LifeCheck() == false)
	{
		gameScene = GAMESCENE_GAMEOVER;
	}
	player->GetScore(enemyManager->EnemyDies());
}

//--------------------------------
// 敵とプレイヤーの当たり判定
//--------------------------------
void GameMainScene::HitCheck_enemy_player()
{
	for (int i = 0; i < enemy->size(); i++)
	{
		//エネミーは正常か
		if ((*enemy)[i] != nullptr)
		{
			//当たっているか
			if (player->HitSphere((*enemy)[i]))
			{

			}
		}
	}

}

//--------------------------------
// プレイヤーと弾の当たり判定
//--------------------------------
void GameMainScene::HitCheck_player_bullet()
{
	for (int i = 0; i < bulletsManager->size(ENEMY_BULLETS); i++)
	{
		auto it = bulletsManager->at(ENEMY_BULLETS, i);
		if (player->HitSphere(it))
		{
			player->ReceiveDamage(it->GetDamage());
			bulletsManager->Hit(ENEMY_BULLETS, i);
		}
	}
}

//--------------------------------
// 敵と弾の当たり判定
//--------------------------------
void GameMainScene::HitCheck_enemy_bullet()
{
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
					//30％の確率で生成するaa
					if (GetRand(99) <= 29)item.push_back(new Item((*enemy)[i]->GetLocation(), 0));
				}
				bulletsManager->Hit(PLAYER_BULLETS, j);
			}
		}
	}
}

//---------------------------------
// アイテムとの当たり判定
//---------------------------------
void GameMainScene::HitCheck_item()
{
	for (int i = 0; i < item.size(); i++)
	{
		if (player->HitSphere(item[i]))
		{
			item[i]->GetEffect(player);
			delete item[i];
			item.erase(item.begin() + i);
		}
	}
}