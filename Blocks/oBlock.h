#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class oBlock : public Block
{
    public:
    oBlock(const std::vector<std::vector<char>> &boardPtr);
    ~oBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
