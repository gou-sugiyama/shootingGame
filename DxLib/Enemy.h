#pragma once
#include "CharaBase.h"
class Enemy :
    public CharaBase
{
private:
    //hp
    //point

public:
    void Update() override {}
    void Draw() override {}
    void Hit() override {}
    void HpCheck() {}
    int GetPoint() {}
};

