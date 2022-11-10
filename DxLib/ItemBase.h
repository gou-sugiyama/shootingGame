#pragma once
#include "SphereCollider.h"
class ItemBase :
    public SphereCollider
{
private:
    //speed
    //type
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    //GetType(){return type;}
};

