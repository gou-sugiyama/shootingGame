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
		if (bullets[i]->isScreenOut())
		{
			DrawString(D_SCREEN_SIZE_X / 2, D_SCREEN_SIZE_Y / 2, "aaaaaaaaaaaaaaaaaaaaaaa", 0xffffff);
		}
	}
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
// 
//------------------------------------
