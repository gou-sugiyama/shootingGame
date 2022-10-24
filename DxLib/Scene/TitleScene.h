#pragma once
#include "AbstractScene.h"
class TitleScene :
    public AbstractScene
{
public:
    //コンストラクタ
    TitleScene();
    //デストラクタ
    virtual ~TitleScene() {}


    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;
};

