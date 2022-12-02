#include "board.h"
#include "Levels/level.h"
#include "Levels/lvl0.h"
#include "Levels/lvl1.h"
#include "Levels/lvl2.h"
#include "Levels/lvl3.h"
#include "Levels/lvl4.h"
#include "Blocks/block.h"
#include "Blocks/iBlock.h"
#include "Blocks/jBlock.h"
#include "Blocks/lBlock.h"
#include "Blocks/oBlock.h"
#include "Blocks/sBlock.h"
#include "Blocks/tBlock.h"
#include "Blocks/zBlock.h"
#include "Blocks/cube.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum Op
{
    LEFT,
    RIGHT,
    DOWN,
    CLOCKWISE,
    COUNTERCLOCKWISE,
    DROP,
    LEVEL_UP,
    LEVEL_DOWN,
    NO_RANDOM,
    RANDOM,
    BLOCK,
    RESTART,
    SEQUENCE
};

Op convertOp(string opStr)
{
    vector<string> commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "block", "restart", "sequence"};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (opStr.size() <= commands[i].size() && opStr == commands[i].substr(0, opStr.size()))
        {
            return Op(i);
        }
    }

} // convertOp

Board :: Board(int width, int height, int newLvl, string file, vector<vector<char>> playingBoard) : width{width}, height{height}, blind{false}, heavy{false}, force{false}, score{0}, file{file}, singleCount{0}, lost{false}, playingBoard{playingBoard}
{
    if (newLvl <= 0)
    {
        lvl = new lvl0{file, false};
    }
    else if (newLvl == 1)
    {
        lvl = new lvl1{true};
    }
    else if (newLvl == 2)
    {
        lvl = new lvl2{true};
    }
    else if (newLvl == 3)
    {
        if (file == "")
        {
            lvl = new lvl3{true};
        }
        else
        {
            lvl = new lvl3{false, file};
        }
        heavy = true;
    }
    else
    {
        if (file == "")
        {
            lvl = new lvl4{true};
        }
        else
        {
            lvl = new lvl4{false, file};
        }
        heavy = true;
    }
}

bool Board ::getBlind() { return blind; };
bool Board ::getForce() { return force; };
bool Board::getHeavy() { return heavy; };
int Board ::getScore() { return score; };

bool Board ::checkLose()
{
    if (lost)
    {
        return true;
    }

    for (int i = 0; i < width; i++)
    {
        if (playingBoard[2][i] != ' ')
        {
            return true;
        }
    }
    return false;
};

void Board ::leveldown()
{
    Level *tmp;
    if (lvl->lvlNum() == 0)
    {
        cout << "Minimum level is 0, you cannot go any lower";
        return;
    }
    else if (lvl->lvlNum() == 1)
    {
        tmp = new lvl0{file, false};
    }
    else if (lvl->lvlNum() == 2)
    {
        tmp = new lvl1{true};
    }
    else if (lvl->lvlNum() == 3)
    {
        tmp = new lvl2{true};
    }
    else if (lvl->lvlNum() == 4)
    {
        if (file == "")
        {
            tmp = new lvl3{true};
        }
        else{
            tmp = new lvl3{false, file};
        }
    }

    swap(lvl, tmp);
    delete tmp;
}

void Board ::levelup()
{
    Level *tmp;
    if (lvl->lvlNum() == 4)
    {
        cout << "Max level is 4, you cannot go any higher";
        return;
    }
    else if (lvl->lvlNum() == 0)
    {
        tmp = new lvl1{true};
    }
    else if(lvl -> lvlNum() == 1){
        tmp = new lvl2{true};
    }
    else if (lvl->lvlNum() == 2)
    {
        Level *tmp;
        if (file == "")
        {
            Level *tmp = new lvl3{true};
        }
        else{
            Level* tmp = new lvl3{false, file};
        }
    }
    else
    {
        Level *tmp;
        if (file == "")
        {
            Level *tmp = new lvl4{true};
        }
        else{
            Level* tmp = new lvl4{false, file};
        }
    }

    swap(lvl, tmp);
    delete tmp;
}

void Board :: newBlock()
{
    char type;

    if(file == ""){
        type = lvl -> blockType(true);
    }
    else{
        type = lvl -> blockType(false);
    }
    
    Block *b;

    if(singleCount % 5 == 0 && singleCount != 0){
        b = new cube(playingBoard); // ig we need a new block to be *
        b -> drop();
        // notify observers here to change display
        delete b;
    }
    else if (type == 'i')
    {
        b = new iBlock(playingBoard);
    }
    else if (type == 'j')
    {
        b = new jBlock(playingBoard);
    }
    else if (type == 'l')
    {
        b = new lBlock(playingBoard);
    }
    else if (type == 'o')
    {
        b = new oBlock(playingBoard);
    }
    else if (type == 's')
    {
        b = new sBlock(playingBoard);
    }
    else if (type == 'z')
    {
        b = new zBlock(playingBoard);
    }
    else if (type == 't')
    {
        b = new tBlock(playingBoard);
    }

    // notify observers here to change display
    if(!b -> canCreate()){
        lost = true;
        return;
    }

    cout << "Command: ";
    string command;

    while (cin >> command)
    {
        Op op = convertOp(command);

        switch (op)
        {
        case LEFT:
            b->left();
            break;
        case RIGHT:
            b->right();
            break;
        case DOWN:
            b->down();
            break;
        case CLOCKWISE:
            b->clockwise();
            break;
        case COUNTERCLOCKWISE:
            b->counterClockwise();
            break;
        case DROP:
            b->drop();
            break;
        }
        // notify observers here to change display
        // does block mutate playingBoard as it moves?
    }

    delete b;
    
}

int Board ::clearlines()
{
        // change score
    int clearedlines = 0;

    for (int i = 0; i < height; i++)
    {
        bool fullLine = true;
        for (int j = 0; j < width; j++)
        {
            if (playingBoard[i][j] == ' ')
            {
                fullLine = false;
            }
        }

        if(fullLine){
            clearedlines++;
            playingBoard.erase(playingBoard.begin() + (i - 1));
            vector<char> blankLine(width, ' ');
            playingBoard.insert(playingBoard.begin(), blankLine);

            // notify observers to change display
        }
    }
}

int Board::getWidth()
{
    return width;
};
int Board::getHeight()
{
    return height;
};

char Board::getState(int row, int col) const
{
    return playingBoard[col][row];
}
