#pragma once
#include "common.h"
#include "CharaBase.h"


//デフォルト値
#define PLAYER_RADIUS 10
#define PLAYER_SPEED 2.5
#define PLAYER_LIFE 10
#define PLAYER_BULLET_RADIAN -1.57f

class Player :
    public CharaBase
{
private:
    int lifeImage;
    int score;
    int life;

public:
    Player();
    ~Player();


    void Update() override;
    void Draw() override;
    void DrawLife()const;
    void Controll(); //プレイヤーの操作

    void ReceiveDamage(int damage);
    void Recovery(int amount);
    bool LifeCheck();
    void GetScore(int addScore) { score += addScore; }
    int GetScore() { return score; }
};

