#include "BulletsManager.h"

//------------------------------------
// コンストラクタ
//------------------------------------
BulletsManager::BulletsManager()
{

}

//------------------------------------
// コンストラクタ
//------------------------------------
BulletsManager::BulletsManager(int bullets_max)
{
	bulletsMax = bullets_max;
}

//------------------------------------
// デストラクタ
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
// 更新
//------------------------------------
void BulletsManager::Update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update();
	}
}

//------------------------------------
// 描画
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
// StraightBulletの生成
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
