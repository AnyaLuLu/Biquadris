#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class jBlock : public Block
{
    jBlock();
    ~jBlock();
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
