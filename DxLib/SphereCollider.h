#pragma once
#include "Location.h"

class SphereCollider
{
protected:
	Location location;
	float radius;

public:
	//“–‚½‚è”»’è
	void HitSphere() {}

	Location GetLocation() { return location; }
	void SetLocation(Location location) { this->location = location; }
};

