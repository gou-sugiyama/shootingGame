#include "common.h"
#include "StraightBullet.h"

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
StraightBullet::StraightBullet():BulletsBase()
{

}

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
StraightBullet::StraightBullet
(Location Location, float radius, int damage, float radian, float speed)
	:BulletsBase(Location,radius,damage, radian,speed)
{

}

//-----------------------------------
// �f�X�g���N�^
//-----------------------------------
StraightBullet::~StraightBullet()
{

}

//-----------------------------------
// �X�V
//-----------------------------------
void StraightBullet::Update()
{
	MoveStraght();
}

//-----------------------------------
// �`��
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
