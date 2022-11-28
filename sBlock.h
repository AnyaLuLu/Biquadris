#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class sBlock : public Block
{
    sBlock(const std::vector<std::vector<char>> &boardPtr);
    ~sBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
