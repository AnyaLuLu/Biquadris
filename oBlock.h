#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class oBlock : public Block
{
    public:
    oBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~oBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
    char getType() override;
};

#endif
