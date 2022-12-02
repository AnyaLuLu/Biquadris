#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Block
{
protected:
    std::vector<std::pair<int, int>> blockPos;      // row, col
    std::vector<std::vector<char>> &playingBoard; // col row, since it is a vector of vectors

public:
    Block(std::vector<std::vector<char>> &playingBoard);
    bool left();
    bool right();
    bool down();
    virtual bool clockwise();
    virtual bool counterClockwise();
    bool drop();
    virtual bool canCreate();
    virtual void addBlock();
    virtual ~Block();
};

#endif
