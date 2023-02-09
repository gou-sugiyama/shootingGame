#pragma once
#include "BulletsBase.h"
class StraightBullet :public BulletsBase
{
private:
	

public:
    //コンストラクタ
    StraightBullet();
    StraightBullet(Location Location, float radius,
        int damage, float radian, float speed);
    //デストラクタ
    ~StraightBullet();

    //更新
    void Update() override;
    //描画
    void Draw()const override;
};

