#pragma once
#include "AbstractScene.h"
#include "../Player.h"
#include "../Enemy.h"

#define D_ENEMY_MAX 10

class GameMainScene :
    public AbstractScene
{
private:
    bool debug = false; //TODO:消す　デバッグ

    Player* player;
    Enemy* enemy[D_ENEMY_MAX];

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
    void HitCheck();
    bool HitCheck_enemy_player();

};

