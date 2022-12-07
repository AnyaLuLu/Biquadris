#include "tBlock.h"
#include <utility>
using namespace std;

tBlock::tBlock(vector<vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth)
{
    type = 'T';
    blockPos = {{3, 1}, {2, 0}, {2, 1}, {2, 2}}; // starts on row 3 cuz the rows 0-2 are reserve rows
};
tBlock::~tBlock(){};
bool tBlock::clockwise()
{
    // getting lower left corner
    int llcRow = blockPos[0].first;
    int llcCol = blockPos[0].second;
    for (int i = 1; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first > llcRow)
        {
            llcRow = blockPos[i].first;
        }
        if (blockPos[i].second < llcCol)
        {
            llcCol = blockPos[i].second;
        }
    }

    // determining the orientation. facing determines the direction that the midpoint square is pointing to (i.e. down is the T shape)
    char facing = 'u';
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first + 1 == llcRow && blockPos[i].second - 2 == llcCol)
        {
            facing = 'd';
        }
        else if (blockPos[i].first + 2 == llcRow && blockPos[i].second - 1 == llcCol)
        {
            facing = 'l';
        }
        else if (blockPos[i].first + 2 == llcRow && blockPos[i].second == llcCol)
        {
            facing = 'r';
        }
    }

    // checking that itll rotate in bounds
    if (facing == 'l' || facing == 'r')
    {
        if (llcCol > (boardWidth - 3))
        {
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (facing == 'u')
    {
        if (playingBoard[llcRow - 2][llcCol] != ' ' || playingBoard[llcRow - 1][llcCol] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'r')
    {
        if (playingBoard[llcRow - 1][llcCol + 2] != ' ' || playingBoard[llcRow][llcCol + 1] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'd')
    {
        if (playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'l')
    {
        if (playingBoard[llcRow][llcCol] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            return false;
        }
    }

    // rotating the block
    this->unset();
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (facing == 'r' || facing == 'l')
        {
            if (blockPos[i].first == llcRow && blockPos[i].second == llcCol)
            {
                blockPos[i].first -= 1;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol)
            {
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first += 1;
            }
            else if (blockPos[i].first == llcRow - 2 && blockPos[i].second == llcCol)
            {
                blockPos[i].first += 1;
                blockPos[i].second += 2;
            }
            else if (blockPos[i].first == llcRow - 2 && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first += 2;
                blockPos[i].second += 1;
            }
        }
        else
        {
            if (blockPos[i].first == llcRow && blockPos[i].second == llcCol)
            {
                blockPos[i].first -= 2;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first -= 1;
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 2)
            {
                blockPos[i].second -= 2;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol)
            {
                blockPos[i].first -= 1;
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 1)
            {
                continue;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 2)
            {
                blockPos[i].first += 1;
                blockPos[i].second -= 1;
            }
        }
    }
    this->addBlock();
    return true;
};
bool tBlock::counterClockwise()
{
    // getting lower left corner
    int llcRow = blockPos[0].first;
    int llcCol = blockPos[0].second;
    for (int i = 1; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first > llcRow)
        {
            llcRow = blockPos[i].first;
        }
        if (blockPos[i].second < llcCol)
        {
            llcCol = blockPos[i].second;
        }
    }

    // determining the orientation. facing determines the direction that the midpoint square is pointing to (i.e. down is the T shape)
    char facing = 'u';
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first + 1 == llcRow && blockPos[i].second - 2 == llcCol)
        {
            facing = 'd';
        }
        else if (blockPos[i].first + 2 == llcRow && blockPos[i].second - 1 == llcCol)
        {
            facing = 'l';
        }
        else if (blockPos[i].first + 2 == llcRow && blockPos[i].second == llcCol)
        {
            facing = 'r';
        }
    }

    // checking that itll rotate in bounds
    if (facing == 'l' || facing == 'r')
    {
        if (llcCol > (boardWidth - 3))
        {
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (facing == 'u')
    {
        if (playingBoard[llcRow - 2][llcCol + 1] != ' ' || playingBoard[llcRow - 1][llcCol] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'l')
    {
        if (playingBoard[llcRow - 1][llcCol + 2] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'd')
    {
        if (playingBoard[llcRow][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'r')
    {
        if (playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            return false;
        }
    }

    // rotating the block
    this->unset();
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (facing == 'r' || facing == 'l')
        {
            if (blockPos[i].first == llcRow && blockPos[i].second == llcCol)
            {
                blockPos[i].second += 2;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first -= 1;
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol)
            {
                blockPos[i].first += 1;
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 1)
            {
                continue;
            }
            else if (blockPos[i].first == llcRow - 2 && blockPos[i].second == llcCol)
            {
                blockPos[i].first += 2;
            }
            else if (blockPos[i].first == llcRow - 2 && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first += 1;
                blockPos[i].second -= 1;
            }
        }
        else
        {
            if (blockPos[i].first == llcRow && blockPos[i].second == llcCol)
            {
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first -= 1;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 2)
            {
                blockPos[i].first -= 2;
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol)
            {
                blockPos[i].first += 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 2)
            {
                blockPos[i].first -= 1;
                blockPos[i].second -= 2;
            }
        }
    }
    this->addBlock();
    return true;
};
/*
void tBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[col][row] = 'T';
    }
};*/
bool tBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (playingBoard[2][0] != ' ' || playingBoard[2][1] != ' ' || playingBoard[2][2] != ' ' || playingBoard[3][1] != ' ')
        {
            return false;
        }
    }
    return true;
};

char tBlock ::getType() { return 'T'; }
