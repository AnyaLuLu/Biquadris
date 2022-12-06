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
        if (playingBoard[nextrow][curcol] != ' ')
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
    this->unset();
    // checking for validity
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (blockPos[i].second == boardWidth - 1)
        {
            this->addBlock();
            //std::cerr << "error1";
            return false;
        }
        int currow = blockPos[i].first;
        int nextcol = blockPos[i].second + 1;
        //std::cerr << "currow: "<< currow << std::endl;
        //std::cerr << "nextcol: "<< nextcol << std::endl;
        //std::cerr << "char:"<< playingBoard[currow][nextcol] << "|"<< std::endl;
        if (playingBoard[currow][nextcol] != ' ')
        {
            //std::cerr << "error 2" << std::endl;;
            //std::cerr << "i: "<<i << std::endl;
            this->addBlock();
            return false;
        }
    }
    // actual mutation
    for (int i = 0; i < blockPos.size(); ++i)
    {
        blockPos[i].second++;
        //std::cerr << "here" << std::endl;
        // << blockPos[i].second << std::endl;
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
    if(!(this -> down())){
	return false;
    }

    while (this->down()){};
    return true;
}

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
	    //std::cout << "a block pos has been erased" << std::endl;
        }

	else if(blockPos[i].first < row){
	    blockPos[i].first++;
	    //std::cout << "a block pos has been moved down" << std::endl;
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
