#pragma once
#include "AbstractScene.h"
#include "../BackScreen.h"
class GameOverScene :
    public AbstractScene
{
private:
    BackScreen* back;

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

