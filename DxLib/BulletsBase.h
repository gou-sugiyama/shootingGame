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
    int angle = 0;      //�p�x
    float speed = 0;    //��


public:
    BulletsBase();
    BulletsBase(Location* pLocation, float* pRadius,
        int* damage, int* angle, float* speed);
    //TODO:�����t���R���X�g���N�^�̒��g�������B
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

