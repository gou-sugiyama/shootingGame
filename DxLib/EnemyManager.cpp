#include "EnemyManager.h"

EnemyManager* EnemyManager::_Instance = 0;
int EnemyManager::destroyed = 1;

//---------------------------------------
// コンストラクタ
//---------------------------------------
EnemyManager::EnemyManager()
{
	troublesomeImage = LoadGraph("images/troublesome.png");
	ufoImage = LoadGraph("images/ufo.png");
	timer = 0;
	destroyed = 1;
	isBossAppear = false;

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

//-----------------------------
// 更新
//-----------------------------
bool EnemyManager::Update()
{
	if (timer == 0)
	{
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
	}
	bool isBossDestroyed = false;
	timer++;
	//３秒に１体雑魚沸き
	if (timer % (60 * 3) == 0)
	{
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
	}
	//プレイ１分時点からBOSS沸き
	if (60 * 60 < timer && isBossAppear == false)
	{
		EnemySpawns({ 640,-200 }, ENEMY_RADIUS, 2, 50, 2000);
		enemy[enemy.size() - 1]->GrantingTag();
		isBossAppear = true;
	}

	if (destroyed <= 0)
	{
		isBossDestroyed = true;

	}
	return isBossDestroyed;
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
			score += enemy[i]->GetPoint();
			if (enemy[i]->GetisBoss())
			{
				destroyed--;
			}
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
		enemy.push_back(new Enemy(location, ufoImage));
	}
}

//---------------------------------------
// エネミーの生成
//---------------------------------------
void EnemyManager::EnemySpawns(Location location, float radius, 
	float speed, int hp, int point)
{
	enemy.push_back(new Enemy(location, radius, ufoImage,speed, hp, point));
}

//---------------------------------------
// エネミーの生成
//---------------------------------------
void EnemyManager::TroublesomeSpawns(Location location, const Player* player, float radius,
	float speed, int hp, int point)
{
	if (enemy.size() < ENEMY_MAX)
	{
		enemy.push_back(new Troublesome(location, player, radius, troublesomeImage, speed, hp, point));
	}
}
