#pragma once
#include "AbstractScene.h"
#include "../Player.h"
#include "../Enemy.h"

#define D_ENEMY_MAX 10
#define D_GAMESCENE_MAIN 0
#define D_GAMESCENE_GAMEOVER 1

class GameMainScene :
    public AbstractScene
{
private:
    int gameScene = D_GAMESCENE_MAIN;

    Player* player;
    Enemy* enemy[D_ENEMY_MAX];

public:
    //�R���X�g���N�^
    GameMainScene();
    //�f�X�g���N�^
    ~GameMainScene();

    //�X�V
    AbstractScene* Update()override;
    void GameMainUpdate();
    bool GameOverUpdate();
    //�`��
    void Draw()const override;


    //�����蔻��̌Ăяo��
    void HitCheck();
    bool HitCheck_enemy_player();

};

