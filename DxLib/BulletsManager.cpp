#include "BulletsManager.h"
#include "Player.h"
#include "Enemy.h"

BulletsManager* BulletsManager::_Instance = 0;
/*new StraightBullet({0,0}, 5, 5, -1.57f, 1);*/
//------------------------------------
// �R���X�g���N�^
//------------------------------------
BulletsManager::BulletsManager()
{ 
	bullets.push_back(vector<BulletsBase*>());
	bullets.push_back(vector<BulletsBase*>());
}

//------------------------------------
// �C���X�^���X�̎擾
//------------------------------------
BulletsManager* BulletsManager::GetInstance()
{
	return _Instance;
}

//------------------------------------
// �I�u�W�F�N�g�̐���
//------------------------------------
void BulletsManager::Create()
{
	if (_Instance == 0)
	{
		_Instance = new BulletsManager();
	}
}

//------------------------------------
// �I�u�W�F�N�g�̍폜
//------------------------------------
void BulletsManager::Delete()
{

	delete _Instance;
	_Instance = 0;
}

//------------------------------------
// �f�X�g���N�^
//------------------------------------
BulletsManager::~BulletsManager()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < bullets[i].size(); j++)
		{
			delete bullets[i][j];
		}
	}
	bullets.clear();
}

//------------------------------------
// �X�V
//------------------------------------
void BulletsManager::Update()
{
	DeleteBulletScreenOut();
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < bullets[i].size(); j++)
		{
			bullets[i][j]->Update();
		}
	}
}

//------------------------------------
// �`��
//------------------------------------
void BulletsManager::Draw()const
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < bullets[i].size(); j++)
		{
			bullets[i][j]->Draw();
		}
	}
}

//------------------------------------
// �����ɓ�������
//------------------------------------
void BulletsManager::Hit(int who_has ,int which)
{
	bullets[who_has][which]->Hit();
	delete bullets[who_has][which];
	bullets[who_has].erase(bullets[who_has].begin() + which);
}

//-------------------------------
// �x�N�^�[�z��̑傫����Ԃ�
//-------------------------------
size_t BulletsManager::size(int who_has)const
{
	return bullets[who_has].size();
}

//------------------------------------
// StraightBullet�̐���
//------------------------------------
void BulletsManager::ShotDefaultBullet(Location location, float radian, int chara_type)
{
	if (chara_type > ENEMY_BULLETS)return;

	bullets[chara_type].push_back(new StraightBullet
	(location, D_DEFAULT_RADIUS, D_DEFAULT_DAMAGE, radian, D_DEFAULT_SPEED));

}

//------------------------------------
// ��ʊO�̒e�̍폜
//------------------------------------
void BulletsManager::DeleteBulletScreenOut()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		for (int j = 0; j < bullets[i].size(); j++)
		{
			if (bullets[i][j]->isScreenOut())
			{
				delete bullets[i][j];
				bullets[i].erase(bullets[i].begin() + j);
			}
		}
	}
}

