#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"

class iBlock : public Block
{
    iBlock();
    ~iBlock();
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
