#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Block
{
protected:
    std::vector<std::pair<int, int>> blockPos;      // row, col
    std::vector<std::vector<char>> &playingBoard; // col row, since it is a vector of vectors
    int boardWidth;
    int level;

public:
    Block(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    bool left();
    bool right();
    bool down();
    virtual bool clockwise() = 0;
    virtual bool counterClockwise() = 0;
    bool drop();
    virtual bool canCreate() = 0;
    virtual void addBlock() = 0;
    virtual ~Block();

    int worth(); // return how many points this block is worth
    bool deletePos(int row); // delete all the pairs in this row, return true if its all gone, otherwise false
    std::vector<std::pair<int, int>> getPos(); // I think other Ethan needs this for display, basically return whats in blockPos. Uhm syntax is wrong but idk what its supposed to be (might also need to make blockPos public but that bad oop. We can return a copy of it tho and keep it protected)

    virtual char getType() = 0;
    
};

#endif
