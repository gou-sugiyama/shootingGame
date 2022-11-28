#include "SphereCollider.h"
#include <math.h>


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

	//距離2乗がrange2乗以下だったら当たってる
	if ((pow((double)distance.x, 2.0) + pow((double)distance.y, 2.0)) <= range)//distanceのx2乗+y2乗<=range
	{
		return true;
	}

	return false;

	//TODO:デバッグ　当たり判定 true or false
}