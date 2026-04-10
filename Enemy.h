#pragma once

#include "Character.h"
#include <string>

class Enemy:public Character{
private:
    int expReward;

public:
    Enemy(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY, int exp)
        : Character(n, h, mH, ar, aD, aR, aS, posX, posY), expReward(exp) {}

    int getExpReward() const {return expReward;}
};