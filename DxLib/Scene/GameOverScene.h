#pragma once
#include "AbstractScene.h"
#include "../BackScreen.h"
class GameOverScene :
    public AbstractScene
{
private:
    BackScreen* back;
    int score;
public:
    //コンストラクタ
    GameOverScene(int score);
    //デストラクタ
    ~GameOverScene();

    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;



};

