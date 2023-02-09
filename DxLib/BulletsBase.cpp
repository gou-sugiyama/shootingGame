#define _USE_MATH_DEFINES
#include <math.h>
#include "BulletsBase.h"

//----------------------------
// �R���X�g���N�^
//----------------------------
BulletsBase::BulletsBase()
{
	//SphereCollider�̏�����
	location.x = 0;
	location.y = 0;
	radius = 0;

}

//----------------------------
// �R���X�g���N�^
//----------------------------
BulletsBase::BulletsBase(Location location, float radius,int damage, float radian, float speed)
{
	//SphereCollider�̏�����
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
	//BulletsBase�̏�����
	this->damage = damage;
	this->radian = radian;
	this->speed = speed;
}

//----------------------------
// �f�X�g���N�^
//----------------------------
BulletsBase::~BulletsBase()
{
	;
}

//-----------------------------------------------------
// ��ʊO���H�@�߂�l true:��ʊO�@false:��ʓ�
//-----------------------------------------------------
bool BulletsBase::isScreenOut()
{
	//���̔���
	if (location.x < 0 - radius || D_SCREEN_SIZE_X + radius < location.x)
	{
		//�c�̔���
		if (location.y < 0 - radius || D_SCREEN_SIZE_Y + radius < location.y)
		{
			return false;
		}
	}

	return true;
}

//----------------------------------------------
// �ړ� �x�N�g������x,y�̐����ɕ������ĉ��Z����
//----------------------------------------------
void BulletsBase::MoveStraght()
{
	//x���W�̈ړ�
	location.x += speed * cosf(radian);
	//y���W�̈ړ�
	location.y += speed * sinf(radian);
}