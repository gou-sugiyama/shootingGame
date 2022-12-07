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
// �R���X�g���N�^
//----------------------
SphereCollider::SphereCollider(Location* pLocation, float* pRadius)
{
	location = *pLocation;
	radius = *pRadius;
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
	bool isHit=false;

	//�����𑪂�
	Location distance = this->location - collider->location;
	//��̃R���W�������ڂ����Ƃ��̋���
	float range = this->radius + collider->radius;

	//����2�悪range2��ȉ��������瓖�����Ă�
	if ((powf(distance.x, 2.0f) + powf(distance.y, 2.0f)) <= powf(range,2.0f))//distance��x2��+y2��<=range��2��
	{
		isHit = true;
	}

	return isHit;

}