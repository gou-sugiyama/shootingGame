#pragma once
#define D_SCREEN_SIZE_X 1280
#define D_SCREEN_SIZE_Y 720
//
//#ifdef D_SCREEN_SIZE_X
//#else
//#define D_SCREEN_SIZE_X 1280
//
//#endif
//
//#ifdef D_SCREEN_SIZE_Y
//#else
//#define D_SCREEN_SIZE_Y 720
//
//#endif

#include "SphereCollider.h"
class BulletsBase :
    public SphereCollider
{
private:
    int damage = 0;
protected:
    Location speed = { 0,0 };

    //ベクトル
    int angle = 0;      //角度
    float amount = 0;   //量

public:
    BulletsBase();
    ~BulletsBase();

    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool isScreenOut();
    void Move();
    int GetDamage()
    {
        return damage;
    }
};

