#include "oBlock.h"
using namespace std;

oBlock::oBlock(const vector<vector<char>> &boardPtr) : Block(boardPtr)
{
    blockPos = {pair(3, 0), pair(3, 1), pair(2, 0), pair(2, 1)}; // starts on row 3 cuz the rows 0-2 are reserve rows
};
oBlock::~oBlock(){};
bool oBlock::clockwise()
{
    return true; // cuz the oblock can always be rotated
};

bool oBlock::counterClockwise()
{
    return true; // cuz the oblock can always be rotated
};

void oBlock::addBlock()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        int row = blockPos[i].first;
        int col = blockPos[i].second;
        boardPtr.playingBoard[col][row] = 'O';
    }
};
bool oBlock::canCreate()
{
    for (int i = 0; i < blockPos.size(); ++i)
    {
        if (boardPtr.playingBoard[0][3] != ' ' || boardPtr.playingBoard[1][3] != ' ' || boardPtr.playingBoard[0][2] != ' ' || boardPtr.playingBoard[1][2] != ' ')
        {
            return false;
        }
    }
    return true;
};
