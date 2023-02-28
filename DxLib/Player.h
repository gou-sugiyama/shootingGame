#pragma once
#include "common.h"
#include "CharaBase.h"


//デフォルト値
#define PLAYER_RADIUS 10
#define PLAYER_SPEED 1
#define PLAYER_LIFE 10
#define PLAYER_BULLET_RADIAN -1.57f

class Player :
    public CharaBase
{
private:
    int score;
    int life;

public:
    Player();
    ~Player();


    void Update() override;
    void Draw() override;
    void Controll(); //プレイヤーの操作

    void Hit() override {}
    void ReceiveDamage(int damage);
    bool LifeCheck();
    int GetScore() {}
};

