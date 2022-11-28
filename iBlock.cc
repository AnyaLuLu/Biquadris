#include "iBlock.h"
using namespace std;

iBlock::iBlock(const vector<vector<char>> &boardPtr) : Block(boardPtr)
{
    blockPos = {pair(3, 0), pair(3, 1), pair(3, 2), pair(3, 3)}; // starts on row 3 cuz the rows 0-2 are reserve rows
};
iBlock::~iBlock(){};
bool iBlock::clockwise()
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

    // determining if it is vertical
    bool isVert = true;
    if (blockPos[0].first == blockPos[1].first)
    {
        isVert = false;
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert)
    {
        if (boardPtr.playingBoard[llcCol + 1][llcRow] != ' ' || boardPtr.playingBoard[llcCol + 2][llcRow] != ' ' || boardPtr.playingBoard[llcCol + 3][llcRow] != ' ')
        {
            return false;
        }
    }
    else
    {
        if (boardPtr.playingBoard[llcCol][llcRow - 1] != ' ' || boardPtr.playingBoard[llcCol][llcRow - 2] != ' ' || boardPtr.playingBoard[llcCol][llcRow + 3] != ' ')
        {
            return false;
        }
    }

    // rotating the block
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (isVert)
        {
            if (blockPos[i].first == llcRow)
            {
                continue;
            }
            else if (blockPos[i].first == llcRow - 1)
            {
                blockPos[i].first += 1;
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 2)
            {
                blockPos[i].first += 2;
                blockPos[i].second += 2;
            }
            else if (blockPos[i].first == llcRow - 3)
            {
                blockPos[i].first += 3;
                blockPos[i].second += 3;
            }
        }
        else
        {
            if (blockPos[i].second == llcCol)
            {
                continue;
            }
            else if (blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first -= 1;
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].second == llcCol + 2)
            {
                blockPos[i].first -= 2;
                blockPos[i].second -= 2;
            }
            else if (blockPos[i].second == llcCol + 3)
            {
                blockPos[i].first -= 3;
                blockPos[i].second -= 3;
            }
        }
    }
    return true;
};

bool iBlock::counterClockwise()
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

    // determining if it is vertical
    bool isVert = true;
    if (blockPos[0].first == blockPos[1].first)
    {
        isVert = false;
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert)
    {
        if (boardPtr.playingBoard[llcCol + 1][llcRow + 1] != ' ' || boardPtr.playingBoard[llcCol + 2][llcRow + 2] != ' ' || boardPtr.playingBoard[llcCol + 3][llcRow + 3] != ' ')
        {
            return false;
        }
    }

    // rotating the block
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (isVert)
        {
            if (blockPos[i].first == llcRow)
            {
                continue;
            }
            else if (blockPos[i].first == llcRow - 1)
            {
                blockPos[i].first += 1;
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 2)
            {
                blockPos[i].first += 2;
                blockPos[i].second += 2;
            }
            else if (blockPos[i].first == llcRow - 3)
            {
                blockPos[i].first += 3;
                blockPos[i].second += 3;
            }
        }
        else
        {
            if (blockPos[i].second == llcCol)
            {
                continue;
            }
            else if (blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first -= 1;
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].second == llcCol + 2)
            {
                blockPos[i].first -= 2;
                blockPos[i].second -= 2;
            }
            else if (blockPos[i].second == llcCol + 3)
            {
                blockPos[i].first -= 3;
                blockPos[i].second -= 3;
            }
        }
    }
    return true;
};

void iBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        boardPtr.playingBoard[col][row] = 'I';
    }
};
bool iBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (boardPtr.playingBoard[0][3] != ' ' || boardPtr.playingBoard[1][3] != ' ' || boardPtr.playingBoard[2][3] != ' ' || boardPtr.playingBoard[3][3] != ' ' ||)
        {
            return false;
        }
    }
    return true;
};
