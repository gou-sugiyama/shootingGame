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
    float moveAngle = 0;
    bool moving = false;   //移動中ならtrue


public:
    Enemy(Location* pLocation);
    ~Enemy();

    void Update() override;
    void Draw() override;

    virtual void Move();
    bool MoveToLocation(Location* pLocation, double frame);
    void MoveStraght() {}
    void Hit() override {}
    void HpCheck() {}
    int GetPoint() {}
};

