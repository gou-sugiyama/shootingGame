#pragma once
#include "Enemy.h"
#include <vector>

#define ENEMY_MAX 3
//�Ӗ� �G�l�~�[�̐����ƍ폜���s��
class EnemyManager
{
private:
	static EnemyManager* _Instance;
	static int destroyed;
	vector<Enemy*> enemy;
	int* Images;

	//�R���X�g���N�^
	EnemyManager();
public:
	static EnemyManager* GetInstance();
	static void Create();
	static void Delete();

	//�f�X�g���N�^
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

