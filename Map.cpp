#include "Map.h"

Map::Map(int width, int hight) : width(width), height(height){
tiles.resize(height);
for (int row=0; row<height;row++){
    tiles[row].resize(width);
}
}



    // void generate();
    // void print() const;
    // bool isWalkable(int x, int y) const;
    // Tiles* getTile(int x, int y);

    // //movement
    // bool moveCharacter(int fromX, int fromY, int toX, int toY);
    // bool placeCharacter(int x,int y, Character* character);
    // bool removeCharacter(int x, int y);