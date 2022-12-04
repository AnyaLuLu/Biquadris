#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class sBlock : public Block
{
    public:
    sBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~sBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    //void addBlock() override;
};

#endif
