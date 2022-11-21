#pragma once
#include "SphereCollider.h"
class BulletsBase :
    public SphereCollider
{
private:
    int damage;
protected:
    Location speed;

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool isScreenOut() = 0;
    int GetDamage()
    {
        return damage;
    }
};

