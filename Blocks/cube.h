#ifndef CUBE_H
#define CUBE_H

#include <vector>

class cube : public Block
{
private:
    std::vector<std::pair<int, int>> blockPos;      // row, col
    const std::vector<std::vector<char>> &boardPtr; // col row, since it is a vector of vectors
public:
    cube(const std::vector<std::vector<char>> &boardPtr);
    bool drop();
    bool canCreate();
    void addBlock();
    ~cube();
};

#endif
