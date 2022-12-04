#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class tBlock : public Block
{
    public:
    tBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~tBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
    char getType() override;
};

#endif
