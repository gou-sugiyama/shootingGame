#pragma once
#include "AbstractScene.h"
#include "../Player.h"

class GameMainScene :
    public AbstractScene
{
private:

    Player* player;
    //*enemy[]

public:
    //コンストラクタ
    GameMainScene();
    //デストラクタ
    ~GameMainScene();

    //更新
    AbstractScene* Update()override;
    //描画
    void Draw()const override;


    //当たり判定の呼び出し
    void HitCheck() {}

};

