#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

class Block
{
protected:
    std::vector<std::pair<int, int>> blockPos;
    const std::vector<std::vector<char>> &boardPtr;

public:
    virtual bool left();
    virtual bool right();
    virtual bool down();
    virtual bool clockwise();
    virtual bool counterClockwise();
    virtual bool drop();
    virtual bool canCreate();
    virtual bool addBlock();
    virtual ~Block();
};

#endif
