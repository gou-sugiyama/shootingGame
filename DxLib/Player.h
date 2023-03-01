#pragma once
#include "common.h"
#include "CharaBase.h"


//デフォルト値
#define PLAYER_RADIUS 25
#define PLAYER_SPEED 1.5
#define PLAYER_LIFE 10
#define PLAYER_BULLET_RADIAN -1.57f

class Player :
    public CharaBase
{
private:
    int images[2];
    int score;
    int life;

public:
    Player();
    ~Player();


    void Update() override;
    void Draw() override;
    void DrawLife()const;
    void Controll(); //プレイヤーの操作

    void Hit() override {}
    void ReceiveDamage(int damage);
    void Recovery(int amount);
    bool LifeCheck();
    void GetScore(int addScore) { score += addScore; }
};

