#include "common.h"
#include "StraightBullet.h"

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
StraightBullet::StraightBullet():BulletsBase()
{
	animTimer = 0;
}

//-----------------------------------
// �R���X�g���N�^
//-----------------------------------
StraightBullet::StraightBullet
(Location Location,int* images, float radius, int damage, float radian, float speed)
	:BulletsBase(Location,images,radius,damage, radian,speed)
{
	animTimer = 0;
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
	animTimer += 1.0 / 20;
	MoveStraght();
}

//-----------------------------------
// �`��
//-----------------------------------
void StraightBullet::Draw()const
{
	DrawRotaGraphF(location.x, location.y, 1.0 / 200 * radius * 3, 0,
		images[int(animTimer) % 2], TRUE);
}

//-----------------------------------
// �����ɓ�������
//-----------------------------------
void StraightBullet::Hit()
{

}

//-----------------------------------
// 
//-----------------------------------
