#include "Mage.h"
#include <iostream>

Mage::Mage(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY)
    : Player(n, h, mH, ar, aD, aR, aS, posX, posY) {}

void Mage::specialAbility(Character& target) {
    int magicalDamage = attackDamage + 10; // Base damage + magical bonus
    int currentHealth = target.getHealth();
    target.takeDamage(magicalDamage + target.getArmor()); // Add armor back to bypass it
}