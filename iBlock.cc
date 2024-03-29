#include "iBlock.h"
#include <iostream>
using namespace std;

iBlock::iBlock(vector<vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth)
{
    blockPos = {{3, 0}, {3, 1}, {3, 2}, {3, 3}}; // starts on row 3 cuz the rows 0-2 are reserve rows
    type = 'I';
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
    // checking that rotating the block would be in bounds
    if (isVert)
    {
        if (llcCol > (boardWidth - 4))
        {
            return false;
        }
    }
    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert)
    {
        if (playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ' || playingBoard[llcRow][llcCol + 3] != ' ')
        {
            return false;
        }
    }
    else
    {
        if (playingBoard[llcRow - 1][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol] != ' ' || playingBoard[llcRow - 3][llcCol] != ' ')
        {
            return false;
        }
    }
    std::cerr << "here" << std::endl;
    this->unset();
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
    this->addBlock();
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

    // checking that rotating the block would be in bounds
    if (isVert)
    {
        if (llcCol > (boardWidth - 4))
        {
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert)
    {
        if (playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ' || playingBoard[llcRow][llcCol + 3] != ' ')
        {
            return false;
        }
    }
    else
    {
        if (playingBoard[llcRow - 1][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol] != ' ' || playingBoard[llcRow - 3][llcCol] != ' ')
        {
            return false;
        }
    }

    this->unset();
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
    this->addBlock();
    return true;
};
/*
void iBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[col][row] = 'I';
    }
};*/
bool iBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (playingBoard[3][0] != ' ' || playingBoard[3][1] != ' ' || playingBoard[3][2] != ' ' || playingBoard[3][3] != ' ')
        {
            return false;
        }
    }
    return true;
};

char iBlock ::getType() { return 'I'; }
