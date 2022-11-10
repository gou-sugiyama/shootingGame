#pragma once
#include "Location.h"

class SphereCollider
{
private:
	Location location;
	float radius;

public:
	void HitSphere() {}
	Location GetLocation() { return location; }
};

