#include "StraightBullet.h"

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

}