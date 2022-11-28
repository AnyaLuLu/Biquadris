#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class tBlock : public Block
{
    tBlock();
    ~tBlock();
    bool left() override;
    bool right() override;
    bool down() override;
    bool clockwise() override;
    bool counterClockwise() override;
    bool drop() override;
    bool canCreate() override;
    bool addBlock() override;
};

#endif
