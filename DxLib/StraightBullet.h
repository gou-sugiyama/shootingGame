#pragma once
#include "BulletsBase.h"
class StraightBullet :public BulletsBase
{
private:
    float animTimer;

public:
    //�R���X�g���N�^
    StraightBullet();
    StraightBullet(Location Location,int* images, float radius,
        int damage, float radian, float speed);
    //�f�X�g���N�^
    ~StraightBullet();

    //�X�V
    void Update() override;
    //�`��
    void Draw()const override;
    //�����ɓ�������
    void Hit() override;
};

