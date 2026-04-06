#include "Rogue.h"
#include <iostream>

Rogue::Rogue(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY)
    : Player(n, h, mH, ar, aD, aR, aS, posX, posY) {}

void Rogue::specialAbility(Character& target) {
    int critDamage = attackDamage * 3; // Triple damage for critical hit
    target.takeDamage(critDamage);
}