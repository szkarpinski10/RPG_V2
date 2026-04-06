#pragma once
#include "Character.h"

class Player: public Character {
protected:
    int level;
    int exp;
    int expToNextLevel;

    public:
        Player(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY);

    int getLevel() const {return level; }
    int getExp() const {return exp; }
    int getExpToNextLevel() const {return expToNextLevel; }

    void gainExp(int amount);
    void levelUp();
    void move(int dx, int dy);
    virtual void specialAbility(Character& target)=0;
    
};
