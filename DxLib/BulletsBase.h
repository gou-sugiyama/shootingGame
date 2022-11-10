#pragma once
#include "SphereCollider.h"
class BulletsBase :
    public SphereCollider
{
private:
    //damage
    //speed

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    int GetDamage(){}
};

