#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class lBlock : public Block
{
    lBlock();
    ~lBlock();
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
