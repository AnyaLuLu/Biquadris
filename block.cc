#include "block.h"
#include <iostream>
Block::Block(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth) : playingBoard(playingBoard), level(level), boardWidth(boardWidth){};

Block::~Block(){};

bool Block::left()
{
    // std::cerr << "charmander";
    this->unset();
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].second == 0)
        {
            this->addBlock();
            return false;
        }
        int nextrow = blockPos[i].first;
        int curcol = blockPos[i].second - 1;
        if (playingBoard[curcol][nextrow] != ' ')
        {
            this->addBlock();
            return false;
        }
        if (nextrow < 0)
        {
            this->addBlock();
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].second--;
    }
    this->addBlock();
    return true;
};

bool Block::right()
{
    // std::cerr << "pikachu";
    this->unset();
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].second == boardWidth - 1)
        {
            this->addBlock();
            std::cerr << "error1";
            return false;
        }
        int nextrow = blockPos[i].first;
        int curcol = blockPos[i].second + 1;
        if (playingBoard[curcol][nextrow] != ' ')
        {
            this->addBlock();
            std::cerr << "error 2";
            return false;
        }
        if (nextrow > boardWidth)
        {
            this->addBlock();
            std::cerr << "error1";
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].second++;
        std::cerr << blockPos[i].second << std::endl;
    }
    this->addBlock();
    return true;
};

bool Block::down()
{
    this->unset();
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int nextcol = blockPos[i].first + 1;
        int currow = blockPos[i].second;
        if (nextcol > 17)
        {
            this->addBlock();
            return false;
        }
        if (playingBoard[nextcol][currow] != ' ')
        {
            this->addBlock();
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].first++;
    }
    this->addBlock();
    return true;
};

bool Block::drop()
{
    while (this->down()){};
    return true;
}
/*
bool Block::drop()
{
    this->unset();
    while (true)
    {
        // checking that it can be dropped
        for (int i = 0; i < blockPos.size(); ++i)
        {
            int nextcol = blockPos[i].first + 1;
            int currow = blockPos[i].second;
            if (nextcol > 17)
            {
                break;
            }
            if (playingBoard[nextcol][currow] != ' ')
            {
                break;
            }
        }
        // actual mutation
        for (int i = 0; i < blockPos.size(); ++i)
        {
            blockPos[i].first++;
        }
    }
    this->addBlock();
    return true; // drop always returns true. the case in which a block cant be dropped means the game ends, and canCreate would be the function to return false
};*/

int Block::worth()
{
    return ((level + 1) * (level + 1));
};

bool Block::deletePos(int row)
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].first == row)
        {
            blockPos.erase(blockPos.begin() + i);
            --i;
        }
    }
    if (blockPos.size() == 0)
    {
        return true;
    }
    return false;
};

std::vector<std::pair<int, int>> Block::getPos()
{
    std::vector<std::pair<int, int>> retPos = blockPos;
    return retPos;
};

void Block::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[row][col] = type;
    }
};
void Block::unset()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[row][col] = ' ';
    }
};
