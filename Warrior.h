#pragma once
#include "Player.h"

class Warrior : public Player {
public:
    Warrior(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY);
    void specialAbility(Character& target) override;
};