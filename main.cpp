#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Character.h"
#include "Map.h"
#include "Game.h"
#include "Menu.h"
#include <iostream>

int main(){

std::cout<<"START"<<std::endl;
Game game;
game.run();
std::cout<<"KONIEC"<<std::endl;
    return 0;
}