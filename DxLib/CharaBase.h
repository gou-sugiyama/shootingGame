#pragma once
#include "SphereCollider.h"
#include "BulletsManager.h"

class CharaBase :
    public SphereCollider
{
protected:
    BulletsManager* bullets;
    Location speed_t = { 1,1 };
    float speed = 1;
    //image

public:
    CharaBase();
    ~CharaBase();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Hit() = 0;
    const vector<StraightBullet*> GetBullets()const
    {
        return bullets->GetBullets();
    }
};

