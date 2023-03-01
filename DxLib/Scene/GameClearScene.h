#pragma once
#include "AbstractScene.h"
#include "../BackScreen.h"
class GameClearScene :
    public AbstractScene
{
private:
    BackScreen* back;
public:
    //�R���X�g���N�^
    GameClearScene();
    //�f�X�g���N�^
    ~GameClearScene();

    //�X�V
    AbstractScene* Update()override;
    //�`��
    void Draw()const override;

};

