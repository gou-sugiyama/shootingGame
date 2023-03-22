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
    //コンストラクタ
    GameClearScene(int score);
    //デストラクタ
    ~GameClearScene();

    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;

};

