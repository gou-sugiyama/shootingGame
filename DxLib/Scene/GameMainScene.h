#pragma once
#include "AbstractScene.h"
#include "../Player.h"

class GameMainScene :
    public AbstractScene
{
private:

    Player* player;
    //*enemy[]

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

