#include "cube.h"

cube::cube(std::vector<std::vector<char>> &playingBoard) : playingBoard(playingBoard){};

cube::~cube(){};

bool cube::drop()
{
    while (true)
    {
        int nextcol = blockPos[0].first + 1;
        int currow = blockPos[0].second;
        if (playingBoard[nextcol][currow] != ' ')
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
    if (playingBoard[8][3] != ' ')
    {
        return false;
    }
    return true;
};

void cube::addBlock()
{
    int row = blockPos[0].first;
    int col = blockPos[0].second;
    playingBoard[col][row] = '*';
};
