#include "EnemyManager.h"

EnemyManager* EnemyManager::_Instance = 0;
int EnemyManager::destroyed = 1;

//---------------------------------------
// �R���X�g���N�^
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
// �C���X�^���X�̎擾
//---------------------------------------
EnemyManager* EnemyManager::GetInstance()
{
	return _Instance;
}

//---------------------------------------
// �}�l�[�W���[�̍쐬
//---------------------------------------
void EnemyManager::Create()
{
	if (_Instance == 0)
	{
		_Instance = new EnemyManager();
	}
}

//---------------------------------------
// �}�l�[�W���[�̍폜
//---------------------------------------
void EnemyManager::Delete()
{
	delete _Instance;
	_Instance = 0;
}

//---------------------------------------
// �f�X�g���N�^
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
// �X�V
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
	//�R�b�ɂP�̎G������
	if (timer % (60 * 3) == 0)
	{
		TroublesomeSpawns({ 640,-200 }, player, ENEMY_RADIUS, 3, 5, 300);
	}
	//�v���C�P�����_����BOSS����
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
// �G�l�~�[�̍폜 �߂�l �폜���ꂽ�G�l�~�[�̍��v�X�R�A
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
// �G�l�~�[�̐���
//---------------------------------------
void EnemyManager::EnemySpawns(Location location)
{
	if (enemy.size() < ENEMY_MAX)
	{
		enemy.push_back(new Enemy(location, ufoImage));
	}
}

//---------------------------------------
// �G�l�~�[�̐���
//---------------------------------------
void EnemyManager::EnemySpawns(Location location, float radius, 
	float speed, int hp, int point)
{
	enemy.push_back(new Enemy(location, radius, ufoImage,speed, hp, point));
}

//---------------------------------------
// �G�l�~�[�̐���
//---------------------------------------
void EnemyManager::TroublesomeSpawns(Location location, const Player* player, float radius,
	float speed, int hp, int point)
{
	if (enemy.size() < ENEMY_MAX)
	{
		enemy.push_back(new Troublesome(location, player, radius, troublesomeImage, speed, hp, point));
	}
}
