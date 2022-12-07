#include "jBlock.h"
#include <iostream>
using namespace std;

jBlock::jBlock(vector<vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth)
{
    blockPos = {{3, 0}, {2, 0}, {3, 1}, {3, 2}}; // starts on row 3 cuz the rows 0-2 are reserve rows
    type = 'J';
};
jBlock::~jBlock(){};
bool jBlock::clockwise()
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
    // determining the orientation. topCorn means corner on top (think about the orientations)
    bool isVert = false;
    bool topCorn = false;
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first + 2 == llcRow && blockPos[i].second - 1 == llcCol)
        {
            isVert = true;
        }
        if (blockPos[i].first + 2 == llcRow && blockPos[i].second == llcCol)
        {
            topCorn = true;
        }
        if (blockPos[i].first + 1 == llcRow && blockPos[i].second - 2 == llcCol)
        {
            topCorn = true;
        }
    }

    // checking that itll rotate in bounds
    if (isVert)
    {
        if (llcCol > (boardWidth - 3))
        {
            std::cerr << "error 1" << std::endl;
            return false;
        }
    }
    // checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert && topCorn)
    {
        if (playingBoard[llcRow - 1][llcCol + 1] != ' ' || playingBoard[llcRow - 1][llcCol + 2] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            // std::cerr << "error 2" << std::endl;
            return false;
        }
    }
    else if (isVert && !topCorn)
    {
        if (playingBoard[llcRow - 1][llcCol] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            // std::cerr << "error 3" << std::endl;
            return false;
        }
    }
    else if (!isVert && !topCorn)
    {
        if (playingBoard[llcRow - 2][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            // std::cerr << "error 4" << std::endl;
            return false;
        }
    }
    else if (!isVert && topCorn)
    {
        if (playingBoard[llcRow][llcCol] != ' ' || playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            // std::cerr << "error 5" << std::endl;
            return false;
        }
    }
    this->unset();
    // rotating the block
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
                // std::cerr<< i << "case 1" << std::endl;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 1)
            {
                blockPos[i].first -= 1;
                blockPos[i].second -= 1;
                // std::cerr<< i << "case 2" << std::endl;
            }
            else if (blockPos[i].first == llcRow && blockPos[i].second == llcCol + 2)
            {
                blockPos[i].second -= 2;
                // std::cerr<< i << "case 3" << std::endl;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol)
            {
                blockPos[i].first -= 1;
                blockPos[i].second += 1;
                // std::cerr<< i << "case 4" << std::endl;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 1)
            {
                // std::cerr<< i << "case 5" << std::endl;
                continue;
            }
            else if (blockPos[i].first == llcRow - 1 && blockPos[i].second == llcCol + 2)
            {
                blockPos[i].first += 1;
                blockPos[i].second -= 1;
                // std::cerr<< i << "case 6" << std::endl;
            }
        }
    }
    this->addBlock();
    return true;
};

bool jBlock::counterClockwise()
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

    // determining the orientation. topCorn means corner on top (think about the orientations)
    bool isVert = false;
    bool topCorn = false;
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first + 2 == llcRow && blockPos[i].second - 1 == llcCol)
        {
            isVert = true;
        }
        if (blockPos[i].first + 2 == llcRow && blockPos[i].second == llcCol)
        {
            topCorn = true;
        }
        if (blockPos[i].first + 1 == llcRow && blockPos[i].second - 2 == llcCol)
        {
            topCorn = true;
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
    // std::cerr<< "checkpoint 1" << std::endl;
    //  checking if it can be rotated. note that playingboard is col, row since it is a vector of vectors
    if (isVert && topCorn)
    {
        if (playingBoard[llcRow][llcCol + 1] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ')
        {
            // std::cerr<< "case 1" << std::endl;
            return false;
        }
    }
    else if (isVert && !topCorn)
    {
        if (playingBoard[llcRow - 1][llcCol] != ' ' || playingBoard[llcRow][llcCol + 2] != ' ' || playingBoard[llcRow - 1][llcCol + 2] != ' ')
        {
            // std::cerr<< "case 2" << std::endl;
            return false;
        }
    }
    else if (!isVert && topCorn)
    {
        if (playingBoard[llcRow][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol] != ' ' || playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            // std::cerr<< "case 3" << std::endl;
            return false;
        }
    }
    else if (!isVert && !topCorn)
    {
        if (playingBoard[llcRow - 1][llcCol + 1] != ' ' || playingBoard[llcRow - 2][llcCol + 1] != ' ')
        {
            // std::cerr<< "case 4" << std::endl;
            return false;
        }
    }
    // std::cerr<< "checkpoint 2" << std::endl;

    this->unset();
    // rotating the block
    // std::cerr<< "called here" << std::endl;
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (isVert)
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
void jBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[col][row] = 'J';
    }
};*/
bool jBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (playingBoard[3][0] != ' ' || playingBoard[3][1] != ' ' || playingBoard[3][2] != ' ' || playingBoard[2][0] != ' ')
        {
            return false;
        }
    }
    return true;
};

char jBlock ::getType() { return 'J'; }
