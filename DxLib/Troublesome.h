#pragma once
#include "Enemy.h"
#include "Player.h"

#define MOVE_AREA_MARGIN 200
#define MOVE_AREA_MAX_H D_SCREEN_SIZE_Y /2
#define SHOT_AT_PLAYER_INTERVAL 60

class Troublesome :
    public Enemy
{
private:
    const Player* player;

public:
    Troublesome(Location location, const Player* player, float radius,
       int image, float speed, int hp, int point);
    ~Troublesome();

    void Update() override;

    virtual void Move();
    void ShotAtPlayer();

    void MakeTargetLocation();
};

