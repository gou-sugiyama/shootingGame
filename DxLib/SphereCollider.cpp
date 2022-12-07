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
// コンストラクタ
//----------------------
SphereCollider::SphereCollider(Location* pLocation, float* pRadius)
{
	location = *pLocation;
	radius = *pRadius;
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
	bool isHit=false;

	//距離を測る
	Location distance = this->location - collider->location;
	//二つのコリジョンが接したときの距離
	float range = this->radius + collider->radius;

	//距離2乗がrange2乗以下だったら当たってる
	if ((powf(distance.x, 2.0f) + powf(distance.y, 2.0f)) <= powf(range,2.0f))//distanceのx2乗+y2乗<=rangeの2乗
	{
		isHit = true;
	}

	return isHit;

}