#pragma once
#include "SphereCollider.h"
#include "BulletsManager.h"

class CharaBase :
    public SphereCollider
{
protected:
    Location speed_t = { 1,1 };
    float speed = 1;
    class BulletsManager* bulletsManager;
    //image

public:
    CharaBase();
    CharaBase(Location location, float radius, float speed);
    ~CharaBase();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;
   
};

