#pragma once
#include "BulletsBase.h"
class StraightBullet :public BulletsBase
{
private:
	

public:
    //�R���X�g���N�^
    StraightBullet();
    StraightBullet(Location Location, float radius,
        int damage, int angle, float speed);
    //�f�X�g���N�^
    ~StraightBullet();

    //�X�V
    void Update() override;
    //�`��
    void Draw()const override;
};

