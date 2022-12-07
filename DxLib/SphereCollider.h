#pragma once
#include "Location.h"

class SphereCollider
{
protected:
	Location location;
	float radius;

public:
	SphereCollider();
	SphereCollider(Location* pLocation, float* pRadius);
	~SphereCollider();

	//�����蔻��
	bool HitSphere(SphereCollider* collider);

	Location GetLocation() { return location; }
	void SetLocation(Location location) { this->location = location; }
};

