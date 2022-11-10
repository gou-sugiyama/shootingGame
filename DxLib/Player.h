#pragma once
#include "CharaBase.h"
class Player :
    public CharaBase
{
private:
    //score
    //life

public:
    void Update() override {}
    void Draw() override {}
    void Hit() override {}
    void LifeCheck() {}
    int GetScore() {}
};

