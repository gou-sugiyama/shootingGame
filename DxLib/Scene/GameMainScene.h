#pragma once
#include "AbstractScene.h"
class GameMainScene :
    public AbstractScene
{
private:


public:
    //コンストラクタ
    GameMainScene();
    //デストラクタ
    ~GameMainScene() {}

    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;
};

