#pragma once
#include "AbstractScene.h"
#include "../Player.h"
#include "../Enemy.h"

#define D_ENEMY_MAX 10

class GameMainScene :
    public AbstractScene
{
private:

    Player* player;
    Enemy* enemy[D_ENEMY_MAX];

public:
    //�R���X�g���N�^
    GameMainScene();
    //�f�X�g���N�^
    ~GameMainScene();

    //�X�V
    AbstractScene* Update()override;
    //�`��
    void Draw()const override;


    //�����蔻��̌Ăяo��
    void HitCheck() {}

};

