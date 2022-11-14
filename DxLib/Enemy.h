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

public:
    Enemy();
    ~Enemy();

    void Update() override;
    void Draw() override;

    void Move();
    void Hit() override {}
    void HpCheck() {}
    int GetPoint() {}
};

