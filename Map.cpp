#include "Map.h"


Map::Map(int width, int height) : width(width), height(height) {}

void Map::generate() {
    tiles.clear(); // czyści poprzednią mapę
    for (int row = 0; row < height; row++) {
        std::vector<Tiles> rowVec;
        for (int col = 0; col < width; col++) {
            bool isWalkable = !(row == 0 || row == height - 1 || col == 0 || col == width - 1);
            rowVec.emplace_back(col, row, isWalkable); // używamy konstruktora parametrowego
        }
        tiles.push_back(std::move(rowVec));
    }
}


void Map::display() const{
    for(int row=0;row<height;row++){
        for(int column=0;column<width;column++){
            if(tiles[row][column].hasOccupant()){
                std::cout<<"O ";
            }
            else if(!tiles[row][column].isWalkable()){
                std::cout<<"# ";
            }
            else{
                std::cout<<"X ";
            }
        }
        std::cout<<std::endl;
    }
}

bool Map::checkIfWalkable(int x, int y) const{
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return tiles[y][x].isWalkable() && !tiles[y][x].hasOccupant();
}

Tiles* Map::getTile(int x, int y){
    if (x < 0 || x >= width || y < 0 || y >= height) return nullptr;
    return &tiles[y][x];
}

    // //movement

bool Map::moveCharacter(int fromX, int fromY, int toX, int toY){
    if (!checkIfWalkable(toX, toY)) return false;
     Character* c = tiles[fromY][fromX].getOccupant();
    if (!c) return false;
    
    tiles[fromY][fromX].clearOccupant();
    tiles[toY][toX].setOccupant(c);
    return true;
}
bool Map::placeCharacter(int x,int y, Character* character){
    if(!checkIfWalkable(x,y)) return false;
    tiles[y][x].setOccupant(character);
    return true;

}
bool Map::removeCharacter(int x, int y){
     if (x < 0 || x >= width || y < 0 || y >= height) return false;
    tiles[y][x].clearOccupant();
    return true;
}