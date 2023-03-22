#pragma once
#include "BulletsBase.h"
class StraightBullet :public BulletsBase
{
private:
    float animTimer;

public:
    //コンストラクタ
    StraightBullet();
    StraightBullet(Location Location,int* images, float radius,
        int damage, float radian, float speed);
    //デストラクタ
    ~StraightBullet();

    //更新
    void Update() override;
    //描画
    void Draw()const override;
    //何かに当たった
    void Hit() override;
};

