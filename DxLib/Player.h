#pragma once
#include "CharaBase.h"

//デフォルト値
#define D_PLAYER_RADIUS 20
#define D_PLAYER_SPEED 4

class Player :
    public CharaBase
{
private:
    float speed;
    //score
    //life

public:
    Player();
    ~Player();


    void Update() override;
    void Draw() override;
    void Controll(); //プレイヤーの操作

    void Hit() override {}
    void LifeCheck() {}
    int GetScore() {}
};

