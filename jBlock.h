#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class jBlock : public Block
{
    public:
    
    jBlock(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth);
    ~jBlock();
    bool clockwise() override;
    bool counterClockwise() override;
    bool canCreate() override;
    //void addBlock() override;
    char getType() override;
};

#endif
