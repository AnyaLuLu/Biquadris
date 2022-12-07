#include "oBlock.h"
//#include <iostream>
using namespace std;

oBlock::oBlock(vector<vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth)
{
    type = 'O';
    blockPos = {{3, 0}, {3, 1}, {2, 0}, {2, 1}}; // starts on row 3 cuz the rows 0-2 are reserve rows
};
oBlock::~oBlock(){};
bool oBlock::clockwise()
{
    //std::cout<<"here"<<std::endl;
    this->unset();
    this->addBlock();
    return true; // cuz the oblock can always be rotated
};

bool oBlock::counterClockwise()
{
    this->unset();
    this->addBlock();
    return true; // cuz the oblock can always be rotated
};
/*
void oBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        playingBoard[col][row] = 'O';
    }
};*/
bool oBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (playingBoard[3][0] != ' ' || playingBoard[3][1] != ' ' || playingBoard[2][0] != ' ' || playingBoard[2][1] != ' ')
        {
            return false;
        }
    }
    return true;
};


char oBlock :: getType(){return 'O';}

