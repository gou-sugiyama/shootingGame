#include "StraightBullet.h"

//----------------------
// コンストラクタ
//----------------------
SphereCollider::SphereCollider()
{
	location = { 0,0 };
	radius = 0;
}

//----------------------
// デストラクタ
//----------------------
SphereCollider::~SphereCollider()
{
	;
}

//--------------------------------------------------
// 当たり判定　戻り値 true:hit false:none
//--------------------------------------------------
bool SphereCollider::HitSphere(SphereCollider* collider)
{
	//距離を測る
	Location distance = this->location - collider->location;
	//二つのコリジョンが接したときの距離
	float range = this->radius + collider->radius;

}