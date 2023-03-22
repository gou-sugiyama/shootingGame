#pragma once
#include "AbstractScene.h"
#include "../BackScreen.h"
class GameClearScene :
    public AbstractScene
{
private:
    BackScreen* back;
    int score;
public:
    //�R���X�g���N�^
    GameClearScene(int score);
    //�f�X�g���N�^
    ~GameClearScene();

    //�X�V
    AbstractScene* Update()override;
    //�`��
    void Draw()const override;

};

