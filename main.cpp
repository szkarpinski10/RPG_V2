#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Character.h"
#include "Map.h"
#include <iostream>

int main(){

std::cout<<"START"<<std::endl;

Map map(10,6);
map.generate();
map.display();

std::cout<<"KONIEC"<<std::endl;
    return 0;
}