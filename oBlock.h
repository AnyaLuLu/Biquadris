#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class oBlock : public Block
{
    oBlock();
    ~oBlock();
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
