#pragma once
#include "SphereCollider.h"
class CharaBase :
    public SphereCollider
{
protected:
    //*bullets
    Location speed_t = { 1,1 };
    float speed = 1;
    //image

public:
   virtual void Update() = 0;
   virtual void Draw() = 0;
   virtual void Hit() = 0;
   //Bullet* GetBullets(){}
};

