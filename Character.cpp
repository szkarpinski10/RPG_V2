#include "Character.h"

Character::Character(std::string n, int h, int ap) : name(n), health(h), maxHealth(h), attackPower(ap) {}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool Character::isAlive() const {
    return health > 0;
}
