#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class lBlock : public Block
{
    public:
    lBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~lBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
    char getType() override;
};

#endif
