#include "CharaBase.h"

//--------------------------------
// コンストラクタ
//--------------------------------
CharaBase::CharaBase()
{
	bulletsManager = BulletsManager::GetInstance();
}

//--------------------------------
// コンストラクタ
//--------------------------------
CharaBase::CharaBase(Location location,float radius,float speed) 
	:SphereCollider(location, radius)
{
	bulletsManager = BulletsManager::GetInstance();
}

//--------------------------------
// デストラクタ
//--------------------------------
CharaBase::~CharaBase()
{

}
