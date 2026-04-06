#include "Warrior.h"
#include <iostream>

Warrior::Warrior(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY)
    : Player(n, h, mH, ar, aD, aR, aS, posX, posY) {}

void Warrior::specialAbility(Character& target) {
    int damage = attackDamage * 2; // Double damage
    target.takeDamage(damage);
}