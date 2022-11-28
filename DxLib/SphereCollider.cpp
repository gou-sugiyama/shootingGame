#include "SphereCollider.h"
#include <math.h>


//----------------------
// �R���X�g���N�^
//----------------------
SphereCollider::SphereCollider()
{
	location = { 0,0 };
	radius = 0;
}

//----------------------
// �f�X�g���N�^
//----------------------
SphereCollider::~SphereCollider()
{
	;
}

//--------------------------------------------------
// �����蔻��@�߂�l true:hit false:none
//--------------------------------------------------
bool SphereCollider::HitSphere(SphereCollider* collider)
{
	//�����𑪂�
	Location distance = this->location - collider->location;
	//��̃R���W�������ڂ����Ƃ��̋���
	float range = this->radius + collider->radius;

	//����2�悪range2��ȉ��������瓖�����Ă�
	if ((pow((double)distance.x, 2.0) + pow((double)distance.y, 2.0)) <= range)//distance��x2��+y2��<=range
	{
		return true;
	}

	return false;

	//TODO:�f�o�b�O�@�����蔻�� true or false
}