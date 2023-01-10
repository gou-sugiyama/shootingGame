#pragma once
#include "common.h"
#include "CharaBase.h"

//デフォルト値
#define D_ENEMY_RADIUS 10
#define D_ENEMY_HP 10
#define D_ENEMY_POINT 100

#define D_ENEMY_MOVELOOP_START 2
#define D_ENEMY_MOVELOOP_END 3

class Enemy :
    public CharaBase
{
private:
    int hp;
    int point;

    //移動用
    float moveAngle = 0;
    bool moving = false;   //移動中ならtrue

    int locationIndex;          //目的座標の添え字に使う
    Location targetLocation;


public:
    Enemy(Location* pLocation);
    ~Enemy();

    void Update() override;
    void Draw() override;

    virtual void Move();
    float GetRadian(Location* pLocation);
    void MoveStraght(float angle);
    void UpdateTargetLocation();
    void Hit() override {}
    void HpCheck() {}
    int GetPoint() {}


    /////////////////
    void Move_t();
    /////////////////
};

