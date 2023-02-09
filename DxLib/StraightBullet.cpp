#include "common.h"
#include "StraightBullet.h"

//-----------------------------------
// コンストラクタ
//-----------------------------------
StraightBullet::StraightBullet():BulletsBase()
{

}

//-----------------------------------
// コンストラクタ
//-----------------------------------
StraightBullet::StraightBullet
(Location Location, float radius, int damage, float radian, float speed)
	:BulletsBase(Location,radius,damage, radian,speed)
{

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
	MoveStraght();
}

//-----------------------------------
// 描画
//-----------------------------------
void StraightBullet::Draw()const
{
	DrawCircleAA(location.x, location.y, radius, 10, 0xffffff);
}

//-----------------------------------
// 
//-----------------------------------


//-----------------------------------
// 
//-----------------------------------
