#include "BulletsManager.h"

//------------------------------------
// �R���X�g���N�^
//------------------------------------
BulletsManager::BulletsManager()
{

}

//------------------------------------
// �R���X�g���N�^
//------------------------------------
BulletsManager::BulletsManager(int bullets_max)
{
	bulletsMax = bullets_max;
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

