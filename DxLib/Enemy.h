#pragma once
#include "common.h"
#include "CharaBase.h"

//デフォルト値
#define D_ENEMY_RADIUS 10
#define D_ENEMY_HP 10
#define D_ENEMY_POINT 100

struct MoveInformation
{
    Location targetLocation_t;
    int pattern;				//0:移動 1:止まる
    int waitTimeFrame;
    int attackPattern;			//0:攻撃しない　1:攻撃する 2:移動しながら攻撃
    int next;
};

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
    MoveInformation moveInfo[5];
    int current = 0;
    int waitTime = 0;

public:
    Enemy(Location pLocation);
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
    void InputCSV();
    void Move_t();
    /////////////////
};

