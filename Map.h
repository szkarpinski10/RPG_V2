#pragma once

#include <vector>
#include <iostream>
#include "Tiles.h"


class Map {
private:
    int width;
    int height;
    std::vector<std::vector<Tiles>> tiles;

public:
    Map(int w, int h);

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void generate();
    void display() const;
    bool checkIfWalkable(int x, int y) const;
    Tiles* getTile(int x, int y);

    //movement
    bool moveCharacter(int fromX, int fromY, int toX, int toY);
    bool placeCharacter(int x,int y, Character* character);
    bool removeCharacter(int x, int y);
}; 