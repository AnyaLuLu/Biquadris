#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class iBlock : public Block
{
public:
    iBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~iBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    //void addBlock() override;
};

#endif
