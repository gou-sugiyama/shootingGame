#pragma once
#include "AbstractScene.h"
class GameMainScene :
    public AbstractScene
{
private:


public:
    //�R���X�g���N�^
    GameMainScene();
    //�f�X�g���N�^
    ~GameMainScene() {}

    //�X�V
    AbstractScene* Update()override;
    //�`��
    void Draw()const override;
};

