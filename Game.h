#pragma once

#include "Map.h"
#include "Character.h"

class Game {
private:
    Map map;
    Character* player;
    int playerX;
    int playerY;
    bool running;

public:
    Game();
    ~Game();

    void run();
    void handleInput();
    void update();
    void render();

};