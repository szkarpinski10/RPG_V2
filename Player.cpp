#include "Player.h"
#include <string>
#include <iostream>

Player::Player(std::string n, int h, int mH, int ar, int aD, float aR, float aS, int posX, int posY)
    : Character(n, h, mH, ar, aD, aR, aS, posX, posY) {
    level = 1;
    exp = 0;
    expToNextLevel = 100;
}

void Player::gainExp(int amount) {
    exp += amount;
    std::cout << name << " gained " << amount << " experience points!" << std::endl;
    
    while (exp >= expToNextLevel) {
        levelUp();
    }
}

void Player::levelUp() {
    exp -= expToNextLevel;
    level++;
    expToNextLevel = level * 100; // Each level requires more exp
    
    // Increase stats on level up
    maxHealth += 10;
    health = maxHealth; // Full heal on level up
    attackDamage += 2;
    std::cout << name << " leveled up to level " << level << "!" << std::endl;
    
}

void Player::move(int dx, int dy) {
    std::cout << name << " moved to position (" << x << ", " << y << ")" << std::endl;
    setPosition(x + dx, y + dy);
}