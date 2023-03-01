#pragma once
#include "common.h"
#include "CharaBase.h"

//デフォルト値
#define ENEMY_RADIUS 10
#define ENEMY_HP 5
#define ENEMY_SPEED 1
#define ENEMY_POINT 100
#define ENEMY_BULLET_RADIAN 1.57
#define DEFAULT_ATTACK_INTERVAL 45
#define CIRCLE_ATTACK_INTERVAL 3

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
    int shotNum;

    //移動用
    float moveAngle;
    int moveControlTime;
    MoveInformation moveInfo[5];
    int current = 0;
    int waitTime = 0;
    int attackInterval;

public:
    Enemy(Location location);
    ~Enemy();

    void Update() override;
    void Draw() override;

    //下に撃つ
    void DefaultShot();
    //8方向に撃つ
    void CircleShot();

    virtual void Move();
    float GetRadian(Location location);
    void MoveStraght(float radian);
    bool CheckArrival();
    void Hit() override {}
    void ReceiveDamage(int damage);
    bool HpCheck();
    int GetPoint() { return point; }


    /////////////////
    void InputCSV();
    void Move_t();
    /////////////////
};

