#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class iBlock : public Block
{
    iBlock(const std::vector<std::vector<char>> &boardPtr);
    ~iBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
