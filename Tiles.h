#pragma once

class Character;

class Tiles{
private:
    int x;
    int y;
    bool walkable;
    Character* occupant;


public:
    
   Tiles(int x, int y, bool walkable)
        : x(x), y(y), walkable(walkable), occupant(nullptr) {}
    ~Tiles() = default;

    int getX() const { return x; }
    int getY() const { return y; }
    bool isWalkable() const { return walkable; }
    bool hasOccupant() const { return occupant != nullptr; }
    Character* getOccupant() const { return occupant; }

    void setOccupant(Character* character){
         occupant = character; 
        }
        
    void clearOccupant(){
         occupant = nullptr; 
        }

};



