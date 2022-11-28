#include "block.h"
Block::Block(const std::vector<std::vector<char>> &boardPtr) : boardPtr(boardPtr){};

Block::~Block(){};

bool Block::left()
{
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int curcol = blockPos[i].first;
        int nextrow = blockPos[i].second - 1;
        if (boardPtr.playingBoard[curcol][nextrow] != ' ')
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
        if (boardPtr.playingBoard[curcol][nextrow] != ' ')
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
        if (boardPtr.playingBoard[nextcol][currow] != ' ')
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
            if (boardPtr.playingBoard[nextcol][currow] != ' ')
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
