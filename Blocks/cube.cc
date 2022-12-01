#include "cube.h"

cube::cube(const std::vector<std::vector<char>> &boardPtr) : boardPtr(boardPtr){};

cube::~cube(){};

bool cube::drop()
{
    while (true)
    {
        int nextcol = blockPos[0].first + 1;
        int currow = blockPos[0].second;
        if (boardPtr.playingBoard[nextcol][currow] != ' ')
        {
            break;
        }
        if (nextcol > 17)
        {
            break;
        }
        blockPos[0].first++;
    }
    return true; // drop always returns true. the case in which a block cant be dropped means the game ends, and canCreate would be the function to return false
};

bool cube::canCreate()
{
    if (boardPtr.playingBoard[8][3] != ' ')
    {
        return false;
    }
    return true;
};

void cube::addBlock()
{
    int row = blockPos[0].first;
    int col = blockPos[0].second;
    boardPtr.playingBoard[col][row] = '*';
};
