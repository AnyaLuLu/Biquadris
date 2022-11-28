#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class sBlock : public Block
{
    sBlock();
    ~sBlock();
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
