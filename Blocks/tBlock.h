#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class tBlock : public Block
{
    tBlock(const std::vector<std::vector<char>> &boardPtr);
    ~tBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
