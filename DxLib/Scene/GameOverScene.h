#pragma once
#include "AbstractScene.h"
class GameOverScene :
    public AbstractScene
{



public:
    //�R���X�g���N�^
    GameOverScene();
    //�f�X�g���N�^
    ~GameOverScene();

    //�X�V
    AbstractScene* Update()override;
    //�`��
    void Draw()const override;



};

