#pragma once

#include "Map.h"



class Game {
private:
    Map map;
    Character* player;
    std::vector<Character*> enemy;
    int playerX;
    int playerY;
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