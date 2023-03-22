#pragma once
#include "AbstractScene.h"
#include "../Player.h"
#include "../Enemy.h"
#include "../BulletsManager.h"
#include "../EnemyManager.h"
#include "../BackScreen.h"
#include "../Item.h"
#include "../Troublesome.h"

#define GAMESCENE_MAIN 0
#define GAMESCENE_GAMEOVER 1
#define GAMESCENE_GAMECLEAR 2

class GameMainScene :
    public AbstractScene
{
private:
    BulletsManager* bulletsManager;
    EnemyManager* enemyManager;
    int gameScene = GAMESCENE_MAIN;

    Player* player;
    BackScreen* back;
    vector <Enemy*>* enemy;
    vector <Item*> item;


public:
    //コンストラクタ
    GameMainScene();
    //デストラクタ
    ~GameMainScene();

    //更新
    AbstractScene* Update()override;
    void GameMainUpdate();
    bool TransitionTime();
    //描画
    void Draw()const override;


    //当たり判定の呼び出し
    void HitCheck();
    void HitCheck_enemy_player();
    void HitCheck_player_bullet();
    void HitCheck_enemy_bullet();
    void HitCheck_item();

};

