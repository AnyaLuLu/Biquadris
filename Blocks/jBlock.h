#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class jBlock : public Block
{
    public:
    
    jBlock(const std::vector<std::vector<char>> &boardPtr);
    ~jBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
};

#endif
