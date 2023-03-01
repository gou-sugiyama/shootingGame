#pragma once
#include "AbstractScene.h"
#include "../BackScreen.h"
class TitleScene :
    public AbstractScene
{
private:
    BackScreen* back;
public:
    //コンストラクタ
    TitleScene();
    //デストラクタ
    virtual ~TitleScene() { delete back; }


    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;
};

