#pragma once
#include "SphereCollider.h"
class CharaBase :
    public SphereCollider
{
protected:
    //*bullets
    float speed = 0;
    //image

public:
   virtual void Update() = 0;
   virtual void Draw() = 0;
   virtual void Hit() = 0;
   //Bullet* GetBullets(){}
};

