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

Game::~Game(){
    delete player;
     for (Enemy* e : enemies) {
        delete e;
    }
}
//?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????

void Game::run() {
    while (running) {
        render();
        handleInput();
        update();
    }
}

void Game::render() {
    system("cls");
    map.display();
    std::cout << "\n" << player->getName()
              << "  LVL:" << player->getLevel()
              << "  HP:" << player->getHealth()
              << "/" << player->getMaxHealth()
              << "  ATK:" << player->getAttackDamage()
              << "  ARM:" << player->getArmor()
              << "  EXP:" << player->getExp()
              << "/" << player->getExpToNextLevel() << "\n";
    std::cout << "Enemies: " << enemies.size() << "\n";
    std::cout << "WASD = move | Q = quit\n";
}


void Game::handleInput() {
    char input;
    std::cin >> input;

    int newX = player->getX();
    int newY = player->getY();

    switch (input) {
        case 'w': case 'W': newY--; break;
        case 's': case 'S': newY++; break;
        case 'a': case 'A': newX--; break;
        case 'd': case 'D': newX++; break;
        case 'q': case 'Q': running = false; return;
        default: return;
    }

    Character* target = getCharacterAt(newX, newY);
    if (target && target != player) {
        Enemy* enemy = dynamic_cast<Enemy*>(target);
        if (enemy) {
            handleCombat(player, enemy);
        }
        return;
    }

    if (map.moveCharacter(player->getX(), player->getY(), newX, newY)) {
        player->setPosition(newX, newY);
    }
}

void Game::update() {
    cleanupDeadEntities();
    checkVictoryCondition();
}

Character* Game::getCharacterAt(int x, int y) {
    Tiles* tile = map.getTile(x, y);
    if (tile && tile->hasOccupant()) {
        return tile->getOccupant();
    }
    return nullptr;
}

void Game::handleCombat(Character* attacker, Character* defender) {
    std::cout << "\n--- COMBAT vs " << defender->getName() << " ---\n";

    attacker->attackTarget(*defender);
    std::cout << defender->getName() << " HP: " << defender->getHealth() << "\n";

    if (defender->isAlive()) {
        defender->attackTarget(*attacker);
        std::cout << attacker->getName() << " HP: " << attacker->getHealth() << "\n";
    } else {
        std::cout << defender->getName() << " defeated!\n";
        Enemy* e = dynamic_cast<Enemy*>(defender);
        if (e) player->gainExp(e->getExpReward());
    }

    if (!player->isAlive()) {
        std::cout << "You died! Game Over.\n";
        running = false;
    }

    std::cout << "Press enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void Game::cleanupDeadEntities() {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if (!(*it)->isAlive()) {
            map.removeCharacter((*it)->getX(), (*it)->getY());
            delete *it;
            it = enemies.erase(it);
        } else {
            ++it;
        }
    }
}

void Game::checkVictoryCondition() {
    if (enemies.empty()) {
        render();
        std::cout << "\nAll enemies defeated! You win!\n";
        running = false;
    }
}