#pragma once
#include "Enemy.h"
#include "Troublesome.h"
#include "Player.h"
#include <vector>

#define ENEMY_MAX 10
//�Ӗ� �G�l�~�[�̐����ƍ폜���s��
class EnemyManager
{
private:
	static EnemyManager* _Instance;
	static int destroyed;
	vector<Enemy*> enemy;
	int troublesomeImage;
	int ufoImage;

	int timer;
	bool isBossAppear;

	Player* player;
	//�R���X�g���N�^
	EnemyManager();
public:
	static EnemyManager* GetInstance();
	static void Create();
	static void Delete();

	//�X�V
	bool Update();

	//�f�X�g���N�^
	~EnemyManager();

	vector<Enemy*>* GetEnemyInstance()
	{
		return &enemy;
	}

	int EnemyDies();
	void EnemySpawns(Location location);
	void EnemySpawns(Location location, float radius, float speed, int hp, int point);
	void TroublesomeSpawns(Location location, const Player* player, float radius, float speed, int hp, int point);
	void InitDestroyed() { destroyed = 0; }
	void GetPlayerInstance( Player* player) { this->player = player; }
};

