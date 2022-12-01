#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class zBlock : public Block
{
    zBlock(const std::vector<std::vector<char>> &boardPtr);
    ~zBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
