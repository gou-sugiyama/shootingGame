#pragma once
#include "AbstractScene.h"
class TitleScene :
    public AbstractScene
{
public:
    //�R���X�g���N�^
    TitleScene();
    //�f�X�g���N�^
    virtual ~TitleScene() {}


    //�X�V
    AbstractScene* Update()override;
    //�`��
    void Draw()const override;
};

