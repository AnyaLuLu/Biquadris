#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Block
{
protected:
    std::vector<std::pair<int, int>> blockPos;      // row, col
    std::vector<std::vector<char>> &playingBoard; // col row, since it is a vector of vectors
    int level;

public:
    Block(std::vector<std::vector<char>> &playingBoard, int level);
    bool left();
    bool right();
    bool down();
    virtual bool clockwise();
    virtual bool counterClockwise();
    bool drop();
    virtual bool canCreate();
    virtual void addBlock();
    virtual ~Block();


    /**** Ethan's functions to do ****/
    virtual bool deletePos(int row); // = 0 delete all the pairs in this row, return true if its all gone, otherwise false
    int worth(); // return how many points this block is worth
};

#endif
