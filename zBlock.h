#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class zBlock : public Block
{
    zBlock();
    ~zBlock();
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
