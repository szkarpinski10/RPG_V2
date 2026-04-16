#include "Character.h"

Character::Character(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY) 
: name(n), health(h), maxHealth(mH), armor(ar), attackDamage(aD), attackRange(aR), attackSpeed(aS), x(posX), y(posY) {}

void Character::takeDamage(int damage) {
    health = health-(damage-armor);
    if (health < 0) health = 0;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::attackTarget(Character& target){
    target.takeDamage(attackDamage);
}
