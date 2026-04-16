#include "Game.h"
#include "Mage.h"
#include "Rogue.h"
#include "Warrior.h"
#include "Enemy.h"
#include "Menu.h"

#include <conio.h>


Game::Game(): map(20,10),player(nullptr),running(true){
    // menu
    int menuChoice=menu.showMenu();
    if (menuChoice==2){
        running=false;
        return;
    }
    int classChoice=menu.chooseClass();
    // wybor postaci
   switch(classChoice){
    case 1:
        player = new Warrior("Warrior", 150, 150, 10, 20, 1.0f, 0.8f, 1, 1);;
        break;

    case 2:
        player = new Mage("Mage", 80, 80, 2, 30, 3.0f, 1.2f, 1, 1);
        break;

    case 3:
        player = new Rogue("Rogue", 100, 100, 4, 18, 1.0f, 1.5f, 1, 1);
        break;
   }
   map.placeCharacter(1,1,player);

   //enemy
    enemies.push_back(new Enemy("Goblin",   30, 30, 1, 8,  1.0f, 1.2f, 5,  3, 30));
    enemies.push_back(new Enemy("Skeleton", 50, 50, 3, 12, 1.0f, 1.0f, 10, 5, 50));
    enemies.push_back(new Enemy("Orc",      80, 80, 5, 18, 1.0f, 0.7f, 15, 7, 80));

      for (Enemy* e : enemies) {
        map.placeCharacter(e->getX(), e->getY(), e);
    }
}