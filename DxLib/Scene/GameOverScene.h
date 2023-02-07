#pragma once
#include "AbstractScene.h"
class GameOverScene :
    public AbstractScene
{



public:
    //コンストラクタ
    GameOverScene();
    //デストラクタ
    ~GameOverScene();

    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;



};

