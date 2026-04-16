#pragma once

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int maxHealth;
    int armor;

    int attackDamage;
    float attackRange;
    float attackSpeed; 

    int x;
    int y;

public:
    Character(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY);
    virtual ~Character() {}

    // 
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getArmor() const { return armor; }

    int getAttackDamage() const {return attackDamage; }
    float getAttackRange() const { return attackRange; }
    float getAttackSpeed() const { return attackSpeed; }
    
    int getX() const { return x; }
    int getY() const { return y; }

    //
    void setPosition(int newX, int newY){
        x=newX;
        y=newY;
    }
    //
    void takeDamage(int damage);
    bool isAlive() const;
    void attackTarget(Character& target);
};


