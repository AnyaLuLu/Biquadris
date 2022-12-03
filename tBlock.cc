#include "tBlock.h"
using namespace std;

tBlock::tBlock(vector<vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth)
{
    blockPos = {pair(3, 1), pair(2, 0), pair(2, 1), pair(2, 2)}; // starts on row 3 cuz the rows 0-2 are reserve rows
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

    //checking that itll rotate in bounds
    if (facing == 'l' || facing == 'r'){
        if (llcCol > (boardWidth - 3)){
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (facing == 'u')
    {
        if (playingBoard[llcCol][llcRow - 2] != ' ' || playingBoard[llcCol][llcRow - 1] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'r')
    {
        if (playingBoard[llcCol + 2][llcRow - 1] != ' ' || playingBoard[llcCol + 1][llcRow] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'd')
    {
        if (playingBoard[llcCol+1][llcRow-2] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'l')
    {
        if (playingBoard[llcCol][llcRow] != ' ' || playingBoard[llcCol + 2][llcRow] != ' ')
        {
            return false;
        }
    }

    // rotating the block
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
                blockPos[i].second -= 1;
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
            }
        }
    }
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

    //checking that itll rotate in bounds
    if (facing == 'l' || facing == 'r'){
        if (llcCol > (boardWidth - 3)){
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (facing == 'u')
    {
        if (playingBoard[llcCol + 1][llcRow - 2] != ' ' || playingBoard[llcCol][llcRow - 1] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'l')
    {
        if (playingBoard[llcCol + 2][llcRow - 1] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'd')
    {
        if (playingBoard[llcCol][llcRow] != ' ' || playingBoard[llcCol][llcRow - 2] != ' ')
        {
            return false;
        }
    }
    else if (facing == 'r')
    {
        if (playingBoard[llcCol + 1][llcRow] != ' ' || playingBoard[llcCol + 2][llcRow] != ' ')
        {
            return false;
        }
    }

    // rotating the block
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
                blockPos[i].second += 2;
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
                blockPos[i].second += 1;
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
    return true;
};
void tBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[col][row] = 'T';
    }
};
bool tBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (playingBoard[0][2] != ' ' || playingBoard[1][2] != ' ' || playingBoard[2][2] != ' ' || playingBoard[1][3] != ' ')
        {
            return false;
        }
    }
    return true;
};