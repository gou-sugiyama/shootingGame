#pragma once
#include "AbstractScene.h"
#include "../BackScreen.h"
class GameOverScene :
    public AbstractScene
{
private:
    BackScreen* back;

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

