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
void BulletsBase::Move()
{
	//�p�x��0�Ȃ�^��ɓ��� ����ȊO�Ȃ�v�Z����
	if (angle == 0)
	{
		location.y -= amount;
	}
	else
	{
		//TODO : �����ɐ��������̌v�Z
	}
}