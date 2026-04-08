#include "Map.h"
// Map::Map(int width, int height) : width(width), height(height){
// tiles.resize(height);
// for (int row=0; row<height;row++){
//     tiles[row].resize(width);
// }
// }

Map::Map(int width, int height) : width(width), height(height) {
}

// void Map::generate(){
//     for(int row=0; row<height;row++){
//         for(int column=0;column<width;column++){
//             bool isWalkable;
//             if (row==0 || row==height-1|| column==0 || column==width-1) {
//                 isWalkable=false;
//             }
//             else{ 
//                 isWalkable=true; 
//             }

//             tiles[row][column]=Tiles(column,row,isWalkable);
//         }
//     }
// }
void Map::generate() {
    tiles.clear(); // czyści poprzednią mapę
    for (int row = 0; row < height; ++row) {
        std::vector<Tiles> rowVec;
        for (int col = 0; col < width; ++col) {
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
                std::cout<<"W ";
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

//bool checkIfWalkable(int x, int y) const{}
    // Tiles* getTile(int x, int y);

    // //movement
    // bool moveCharacter(int fromX, int fromY, int toX, int toY);
    // bool placeCharacter(int x,int y, Character* character);
    // bool removeCharacter(int x, int y);