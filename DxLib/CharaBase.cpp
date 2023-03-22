#include "CharaBase.h"

//--------------------------------
// �R���X�g���N�^
//--------------------------------
CharaBase::CharaBase()
{
	bulletsManager = BulletsManager::GetInstance();
	speed = 1;
	speed_t = { 1,1 };
}

//--------------------------------
// �R���X�g���N�^
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
// �f�X�g���N�^
//--------------------------------
CharaBase::~CharaBase()
{

}
