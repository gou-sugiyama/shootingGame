#include "CharaBase.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CharaBase::CharaBase()
{
	bulletsManager = BulletsManager::GetInstance();
}

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CharaBase::CharaBase(Location location,float radius,float speed) 
	:SphereCollider(location, radius)
{
	bulletsManager = BulletsManager::GetInstance();
}

//--------------------------------
// �f�X�g���N�^
//--------------------------------
CharaBase::~CharaBase()
{

}
