#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class lBlock : public Block
{
    lBlock(const std::vector<std::vector<char>> &boardPtr);
    ~lBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
