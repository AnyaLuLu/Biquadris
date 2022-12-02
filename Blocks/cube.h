#ifndef CUBE_H
#define CUBE_H

#include "block.h"

class cube : public Block
{
public:
    cube(std::vector<std::vector<char>> &boardPtr);
    bool drop();
    bool canCreate();
    void addBlock();
    ~cube();
};

#endif
