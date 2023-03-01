#include "EnemyManager.h"

EnemyManager* EnemyManager::_Instance = 0;
int EnemyManager::destroyed = 0;

//---------------------------------------
// コンストラクタ
//---------------------------------------
EnemyManager::EnemyManager()
{

}

//---------------------------------------
// インスタンスの取得
//---------------------------------------
EnemyManager* EnemyManager::GetInstance()
{
	return _Instance;
}

//---------------------------------------
// マネージャーの作成
//---------------------------------------
void EnemyManager::Create()
{
	if (_Instance == 0)
	{
		_Instance = new EnemyManager();
	}
}

//---------------------------------------
// マネージャーの削除
//---------------------------------------
void EnemyManager::Delete()
{
	delete _Instance;
	_Instance = 0;
}

//---------------------------------------
// デストラクタ
//---------------------------------------
EnemyManager::~EnemyManager()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		delete enemy[i];
	}
	enemy.clear();
}

//-------------------------------------------------------
// エネミーの削除 戻り値 削除されたエネミーの合計スコア
//-------------------------------------------------------
int EnemyManager::EnemyDies()
{
	int score = 0;
	for (int i = 0; i < enemy.size(); i++)
	{
		if (enemy[i]->HpCheck() == false)
		{
			destroyed++;
			score += enemy[i]->GetPoint();
			delete enemy[i];
			enemy.erase(enemy.begin() + i);
		}
	}

	return score;
}

//---------------------------------------
// エネミーの生成
//---------------------------------------
void EnemyManager::EnemySpawns(Location location)
{
	if (enemy.size() < ENEMY_MAX)
	{
		enemy.push_back(new Enemy(location));
	}
}