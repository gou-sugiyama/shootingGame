#include "BulletsManager.h"
#include "Player.h"
#include "Enemy.h"

BulletsManager* BulletsManager::_Instance = 0;

//------------------------------------
// �R���X�g���N�^
//------------------------------------
BulletsManager::BulletsManager()
{

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
		delete bullets[i];
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
		bullets[i]->Update();
	}
}

//------------------------------------
// �`��
//------------------------------------
void BulletsManager::Draw()const
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Draw();
	}
}

//------------------------------------
// �����ɓ�������
//------------------------------------
void BulletsManager::Hit(int bulletIndex)
{
	bullets[bulletIndex]->Hit();
	delete bullets[bulletIndex];
	bullets.erase(bullets.begin() + bulletIndex);
}

//------------------------------------
// �e�q�̊m��
//------------------------------------
void BulletsManager::SetMagazine(CharaBase chara_base)
{
	
}

//------------------------------------
// StraightBullet�̐���
//------------------------------------
void BulletsManager::ShotDefaultBullet(Location location, float radian)
{
	if (bullets.size() < bulletsMax)
	{
		bullets.push_back
		(new StraightBullet
		(location, D_DEFAULT_RADIUS, D_DEFAULT_DAMAGE, radian, D_DEFAULT_SPEED));
	}
}

//------------------------------------
// ��ʊO�̒e�̍폜
//------------------------------------
void BulletsManager::DeleteBulletScreenOut()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->isScreenOut())
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}
}

