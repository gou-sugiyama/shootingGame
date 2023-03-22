#include "CharaBase.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CharaBase::CharaBase()
{
	bulletsManager = BulletsManager::GetInstance();
	speed = 1;
	speed_t = { 1,1 };
}

//--------------------------------
// コンストラクタ
//--------------------------------
CharaBase::CharaBase(Location location, int image, float radius, float speed)
	:SphereCollider(location, radius)
{
	this->image = image;
	speed_t = { 1,1 };
	this->speed = speed;
	bulletsManager = BulletsManager::GetInstance();
}

//--------------------------------
// デストラクタ
//--------------------------------
CharaBase::~CharaBase()
{

}
