#pragma once
#include "Enemy.h"
#include <vector>

#define ENEMY_MAX 3
//責務 エネミーの生成と削除を行う
class EnemyManager
{
private:
	static EnemyManager* _Instance;
	static int destroyed;
	vector<Enemy*> enemy;
	int* Images;

	//コンストラクタ
	EnemyManager();
public:
	static EnemyManager* GetInstance();
	static void Create();
	static void Delete();

	//デストラクタ
	~EnemyManager();

	vector<Enemy*>* GetEnemyInstance()
	{
		return &enemy;
	}

	int EnemyDies();
	void EnemySpawns(Location location);
	int GetDestroyed() { return destroyed; }
	void InitDestroyed() { destroyed = 0; }
};

