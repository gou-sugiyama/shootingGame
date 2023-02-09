#define _USE_MATH_DEFINES
#include <math.h>
#include "BulletsBase.h"

//----------------------------
// コンストラクタ
//----------------------------
BulletsBase::BulletsBase()
{
	//SphereColliderの初期化
	location.x = 0;
	location.y = 0;
	radius = 0;

}

//----------------------------
// コンストラクタ
//----------------------------
BulletsBase::BulletsBase(Location location, float radius,int damage, float radian, float speed)
{
	//SphereColliderの初期化
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
	//BulletsBaseの初期化
	this->damage = damage;
	this->radian = radian;
	this->speed = speed;
}

//----------------------------
// デストラクタ
//----------------------------
BulletsBase::~BulletsBase()
{
	;
}

//-----------------------------------------------------
// 画面外か？　戻り値 true:画面外　false:画面内
//-----------------------------------------------------
bool BulletsBase::isScreenOut()
{
	//横の判定
	if (location.x < 0 - radius || D_SCREEN_SIZE_X + radius < location.x)
	{
		//縦の判定
		if (location.y < 0 - radius || D_SCREEN_SIZE_Y + radius < location.y)
		{
			return false;
		}
	}

	return true;
}

//----------------------------------------------
// 移動 ベクトルからx,yの成分に分解して加算する
//----------------------------------------------
void BulletsBase::MoveStraght()
{
	//x座標の移動
	location.x += speed * cosf(radian);
	//y座標の移動
	location.y += speed * sinf(radian);
}