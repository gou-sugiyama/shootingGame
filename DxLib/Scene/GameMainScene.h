#pragma once
#include "AbstractScene.h"
#include "../Player.h"
#include "../Enemy.h"
#include "../BulletsManager.h"

#define D_ENEMY_MAX 10
#define D_GAMESCENE_MAIN 0
#define D_GAMESCENE_GAMEOVER 1

class GameMainScene :
    public AbstractScene
{
private:
    BulletsManager* bulletsManager;
    int gameScene = D_GAMESCENE_MAIN;

    Player* player;
    vector <Enemy*> enemy;

public:
    //コンストラクタ
    GameMainScene();
    //デストラクタ
    ~GameMainScene();

    //更新
    AbstractScene* Update()override;
    void GameMainUpdate();
    bool GameOverUpdate();
    //描画
    void Draw()const override;


    //当たり判定の呼び出し
    void HitCheck();
    bool HitCheck_enemy_player();
    bool HitCheck_player_bullet();
    bool HitCheck_enemy_bullet();

};

