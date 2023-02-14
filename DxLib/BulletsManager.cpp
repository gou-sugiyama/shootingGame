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
	DeleteBulletScreenOut();
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
	}
}

//------------------------------------
// 何かに当たった
//------------------------------------
void BulletsManager::Hit(int bulletIndex)
{
	bullets[bulletIndex]->Hit();
	delete bullets[bulletIndex];
	bullets.erase(bullets.begin() + bulletIndex);
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
// 画面外の弾の削除
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

