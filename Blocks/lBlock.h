#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class lBlock : public Block
{
    public:
    lBlock(std::vector<std::vector<char>> &playingBoard);
    ~lBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
