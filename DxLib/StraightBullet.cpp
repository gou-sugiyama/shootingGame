#include "common.h"
#include "StraightBullet.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
StraightBullet::StraightBullet():BulletsBase()
{
	animTimer = 0;
}

//-----------------------------------
// コンストラクタ
//-----------------------------------
StraightBullet::StraightBullet
(Location Location,int* images, float radius, int damage, float radian, float speed)
	:BulletsBase(Location,images,radius,damage, radian,speed)
{
	animTimer = 0;
}

//-----------------------------------
// デストラクタ
//-----------------------------------
StraightBullet::~StraightBullet()
{

}

//-----------------------------------
// 更新
//-----------------------------------
void StraightBullet::Update()
{
	animTimer += 1.0 / 20;
	MoveStraght();
}

//-----------------------------------
// 描画
//-----------------------------------
void StraightBullet::Draw()const
{
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * radius * 3, 0,
		images[int(animTimer) % 2], TRUE);
}

//-----------------------------------
// 何かに当たった
//-----------------------------------
void StraightBullet::Hit()
{

}

//-----------------------------------
// 
//-----------------------------------
