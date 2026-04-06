#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int attackPower;

public:
    Character(std::string n, int h, int ap);
    virtual ~Character() {}

    // Getters
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getAttackPower() const { return attackPower; }

    // Virtual functions
    virtual void takeDamage(int damage);
    virtual bool isAlive() const;

    // Pure virtual function to make it abstract
    virtual void specialAbility() = 0;
};

#endif
