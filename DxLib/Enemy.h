#pragma once
#include "common.h"
#include "CharaBase.h"

//�f�t�H���g�l
#define ENEMY_HP 5
#define ENEMY_RADIUS 20
#define ENEMY_SPEED 1
#define ENEMY_POINT 100
#define ENEMY_BULLET_RADIAN 1.57
#define DEFAULT_ATTACK_INTERVAL 45
#define CIRCLE_ATTACK_INTERVAL 3

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
protected:
    int hp;
    int point;
    int shotNum;
    bool isBoss;

    //�ړ��p
    float moveAngle;
    int moveControlTime;
    Location targetLocation;
    MoveInformation moveInfo[5];
    int current = 0;
    int waitTime = 0;

    int attackInterval;

public:
    Enemy(Location location, int image);
    Enemy(Location location, float radius,int image, float speed, int hp, int point);
    ~Enemy();

    void Update() override;
    void Draw() override;

    //���Ɍ���
    void DefaultShot();
    //8�����Ɍ���
    void CircleShot();

    virtual void Move();
    float GetRadian(Location location);
    void MoveStraght();
    bool MoveStraghtToTarget();
    void ReceiveDamage(int damage);
    bool HpCheck();
    int GetPoint() { return point; }

    void GrantingTag() { isBoss = true; }
    bool GetisBoss()const { return isBoss; }

    //���Ƃō������`//
    void InputCSV();
    void Move_t();
    //////////////////////
};

