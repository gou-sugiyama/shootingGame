#pragma once
#include "SphereCollider.h"
#include "BulletsManager.h"

class CharaBase :
    public SphereCollider
{
protected:
    Location speed_t;
    float speed;
    class BulletsManager* bulletsManager;
    int image;

public:
    CharaBase();
    CharaBase(Location location, int image, float radius, float speed);
    ~CharaBase();
	virtual void Update() = 0;
	virtual void Draw() = 0;
   
};

