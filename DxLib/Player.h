#pragma once
#include "common.h"
#include "CharaBase.h"


//�f�t�H���g�l
#define D_PLAYER_RADIUS 20
#define D_PLAYER_SPEED 1
#define D_PLAYER_BULLET_RADIAN -1.57f

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
    void Controll(); //�v���C���[�̑���

    void Hit() override {}
    void LifeCheck() {}
    int GetScore() {}
};

