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
    //�R���X�g���N�^
    GameMainScene();
    //�f�X�g���N�^
    ~GameMainScene();

    //�X�V
    AbstractScene* Update()override;
    void GameMainUpdate();
    bool TransitionTime();
    //�`��
    void Draw()const override;


    //�����蔻��̌Ăяo��
    void HitCheck();
    void HitCheck_enemy_player();
    void HitCheck_player_bullet();
    void HitCheck_enemy_bullet();
    void HitCheck_item();

};

