#include "block.h"
Block::Block(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth) : playingBoard(playingBoard), level(level), boardWidth(boardWidth){};

Block::~Block(){};

bool Block::left()
{
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int curcol = blockPos[i].first;
        int nextrow = blockPos[i].second - 1;
        if (playingBoard[curcol][nextrow] != ' ')
        {
            return false;
        }
        if (nextrow < 0)
        {
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].second--;
    }
    return true;
};

bool Block::right()
{
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int curcol = blockPos[i].first;
        int nextrow = blockPos[i].second + 1;
        if (playingBoard[curcol][nextrow] != ' ')
        {
            return false;
        }
        if (nextrow > 10)
        {
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].second++;
    }
    return true;
};

bool Block::down()
{
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int nextcol = blockPos[i].first + 1;
        int currow = blockPos[i].second;
        if (playingBoard[nextcol][currow] != ' ')
        {
            return false;
        }
        if (nextcol > 17)
        {
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].first++;
    }
    return true;
};

bool Block::drop()
{
    while (true)
    {
        // checking that it can be dropped
        for (int i = 0; i < blockPos.size(); ++i)
        {
            int nextcol = blockPos[i].first + 1;
            int currow = blockPos[i].second;
            if (playingBoard[nextcol][currow] != ' ')
            {
                break;
            }
            if (nextcol > 17)
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
    return true; // drop always returns true. the case in which a block cant be dropped means the game ends, and canCreate would be the function to return false
};

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

std::vector<std::pair<int, int>> Block::getPos(){
    std::vector<std::pair<int, int>> retPos = blockPos;
    return retPos;
};
