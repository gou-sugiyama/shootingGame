#include "EnemyManager.h"

EnemyManager* EnemyManager::_Instance = 0;
int EnemyManager::destroyed = 0;

//---------------------------------------
// �R���X�g���N�^
//---------------------------------------
EnemyManager::EnemyManager()
{

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
			destroyed++;
			score += enemy[i]->GetPoint();
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
		enemy.push_back(new Enemy(location));
	}
}