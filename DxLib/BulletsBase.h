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
    //�x�N�g��
    float radian = 0;      //�p�x
    float speed = 0;    //��
    int* images;

public:
    BulletsBase();
    BulletsBase(Location location,int* images ,float radius,
        int damage, float radian, float speed);
    ~BulletsBase();

    virtual void Update() = 0;
    virtual void Draw()const = 0;
    virtual void Hit() = 0;
    virtual bool isScreenOut();
    void MoveStraght();
    int GetDamage()
    {
        return damage;
    }
};

