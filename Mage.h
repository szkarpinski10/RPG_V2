#pragma once
#include "Player.h"

class Mage : public Player {
public:
    Mage(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY);
    void specialAbility(Character& target) override;
};