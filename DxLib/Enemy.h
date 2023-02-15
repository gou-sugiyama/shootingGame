#pragma once
#include "common.h"
#include "CharaBase.h"

//�f�t�H���g�l
#define D_ENEMY_RADIUS 10
#define D_ENEMY_HP 10
#define D_ENEMY_POINT 100

struct MoveInformation
{
    Location targetLocation_t;
    int pattern;				//0:�ړ� 1:�~�܂�
    int waitTimeFrame;
    int attackPattern;			//0:�U�����Ȃ��@1:�U������ 2:�ړ����Ȃ���U��
    int next;
};

class Enemy :
    public CharaBase
{
private:
    int hp;
    int point;

    //�ړ��p
    bool moving = false;   //�ړ����Ȃ�true
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

