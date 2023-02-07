#pragma once
#define D_SCREEN_SIZE_X 1280
#define D_SCREEN_SIZE_Y 720

#include "SphereCollider.h"
class BulletsBase :
    public SphereCollider
{
private:
    int damage = 0;
protected:
    //ベクトル
    int radian = 0;      //角度
    float speed = 0;    //量


public:
    BulletsBase();
    BulletsBase(Location Location, float radius,
        int damage, int angle, float speed);
    ~BulletsBase();

    virtual void Update() = 0;
    virtual void Draw()const = 0;
    virtual bool isScreenOut();
    void MoveStraght();
    int GetDamage()
    {
        return damage;
    }
};

