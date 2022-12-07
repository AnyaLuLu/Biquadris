#include "zBlock.h"
//#include <iostream>
using namespace std;

zBlock::zBlock(vector<vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth)
{
    type = 'Z';
    blockPos = {{2, 0}, {2, 1}, {3, 1}, {3, 2}}; // starts on row 3 cuz the rows 0-2 are reserve rows
};
zBlock::~zBlock(){};
bool zBlock::clockwise()
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

    // determining the orientation
    bool isVert = false;
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first == llcRow && blockPos[i].second == llcCol)
        {
            isVert = true;
        }
    }

    // checking that itll rotate in bounds
    if (isVert)
    {
        if (llcCol > (boardWidth - 3))
        {
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert)
    {
        if (playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            return false;
        }
    }
    else
    {
        if (playingBoard[llcRow][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            return false;
        }
    }

    // rotating the block
    this->unset();
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (isVert)
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
                // std::cerr<< i << "case 1" << std::endl;
                blockPos[i].first -= 2;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 1)
            {
                // std::cerr<< i << "case 2" << std::endl;
                blockPos[i].first -= 1;
                blockPos[i].second -= 1;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 2)
            {
                // std::cerr<< i << "case 3" << std::endl;
                blockPos[i].second -= 2;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol)
            {
                // std::cerr<< i << "case 4" << std::endl;
                blockPos[i].first -= 1;
                blockPos[i].second += 1;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 1)
            {
                // std::cerr<< i << "case 5" << std::endl;
                continue;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 2)
            {
                // std::cerr<< i << "case 6" << std::endl;
                blockPos[i].first += 1;
                blockPos[i].second -= 1;
            }
        }
    }
    this->addBlock();
    return true;
};

bool zBlock::counterClockwise() // code is the exact same as clockwise cuz it does the same thi g
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

    // determining the orientation
    bool isVert = false;
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first == llcRow && blockPos[i].second == llcCol)
        {
            isVert = true;
        }
    }

    // checking that itll rotate in bounds
    if (isVert)
    {
        if (llcCol > (boardWidth - 3))
        {
            return false;
        }
    }

    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert)
    {
        if (playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            return false;
        }
    }
    else
    {
        if (playingBoard[llcRow][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            return false;
        }
    }

    // rotating the block
    this->unset();
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (isVert)
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
/*
void zBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[col][row] = 'Z';
    }
};*/
bool zBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (playingBoard[2][0] != ' ' || playingBoard[2][1] != ' ' || playingBoard[3][1] != ' ' || playingBoard[3][2] != ' ')
        {
            return false;
        }
    }
    return true;
};

char zBlock::getType() { return 'Z'; }
