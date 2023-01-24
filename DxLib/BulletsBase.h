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
    int angle = 0;      //角度
    float speed = 0;    //量


public:
    BulletsBase();
    BulletsBase(Location* pLocation, float* pRadius,
        int* damage, int* angle, float* speed);
    //TODO:引数付きコンストラクタの中身を書く。
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

