#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class zBlock : public Block
{
    public:
    zBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~zBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    void addBlock() override;
    char getType() override;
};

#endif
