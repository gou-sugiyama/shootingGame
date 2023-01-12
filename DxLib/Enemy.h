#pragma once
#include "common.h"
#include "CharaBase.h"

//デフォルト値
#define D_ENEMY_RADIUS 10
#define D_ENEMY_HP 10
#define D_ENEMY_POINT 100


class Enemy :
    public CharaBase
{
private:
    int hp;
    int point;

    //移動用
    bool moving = false;   //移動中ならtrue
    float moveAngle=0;
    int moveControlTime = 0;

public:
    Enemy(Location* pLocation);
    ~Enemy();

    void Update() override;
    void Draw() override;

    virtual void Move();
    float GetRadian(Location* pLocation);
    void MoveStraght(float radian);
    bool CheckArrival();
    void Hit() override {}
    void HpCheck() {}
    int GetPoint() {}


    /////////////////
    void Move_t();
    /////////////////
};

