#include "cube.h"

cube::cube(std::vector<std::vector<char>> &playingBoard, int level, int boardWidth) : Block(playingBoard, level, boardWidth){
    blockPos = {{3, boardWidth/2}};
};

cube::~cube(){};

bool cube::canCreate()
{
    if (playingBoard[8][3] != ' ')
    {
        return false;
    }
    return true;
};

void cube::addBlock()
{
    int row = blockPos[0].first;
    int col = blockPos[0].second;
    playingBoard[col][row] = '*';
};

bool cube::clockwise(){
    return true;
}

bool cube::counterClockwise(){
    return true;
}

char cube :: getType(){return '*';}
