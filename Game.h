#pragma once

#include "Map.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"
#include <vector>


class Game {
private:
    Menu menu;
    Map map;
    Player* player;
    std::vector<Enemy*> enemies;
    bool running;

    Character* getCharacterAt(int x, int y); 
    void handleCombat(Character* attacker, Character* defender); 
    void cleanupDeadEntities(); 
    void checkVictoryCondition(); 

public:
    Game();
    ~Game();

    void run();
    void handleInput();
    void update();
    void render();

};