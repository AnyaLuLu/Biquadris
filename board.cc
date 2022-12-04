#include "board.h"
#include "level.h"
#include "lvl0.h"
#include "lvl1.h"
#include "lvl2.h"
#include "lvl3.h"
#include "lvl4.h"
#include "block.h"
#include "iBlock.h"
#include "jBlock.h"
#include "lBlock.h"
#include "oBlock.h"
#include "sBlock.h"
#include "tBlock.h"
#include "zBlock.h"
#include "cube.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Board ::Board(int width, int height, int newLvl, string file, vector<vector<char>> playingBoard) : width{width}, height{height}, blind{false}, heavy{false}, force{false}, score{0}, file{file}, singleCount{0}, lost{false}, playingBoard{playingBoard}, playingBlocks{}
{

    /**** If there is no file associated with the lvl, please input empty string for file *****/
    if (newLvl <= 0)
    {
        lvl = new lvl0{file, false};
        currentBlock = this->assignBlock(false);
        nextBlock = this->assignBlock(false);
    }
    else if (newLvl == 1)
    {
        lvl = new lvl1{true};
        currentBlock = this->assignBlock(true);
        nextBlock = this->assignBlock(true);
    }
    else if (newLvl == 2)
    {
        lvl = new lvl2{true};
        currentBlock = this->assignBlock(true);
        nextBlock = this->assignBlock(true);
    }
    else if (newLvl == 3)
    {
        if (file == "")
        {
            lvl = new lvl3{true};
            currentBlock = this->assignBlock(true);
            nextBlock = this->assignBlock(true);
        }
        else
        {
            lvl = new lvl3{false, file};
            currentBlock = this->assignBlock(false);
            nextBlock = this->assignBlock(false);
        }
        heavy = true;
    }
    else
    {
        if (file == "")
        {
            lvl = new lvl4{true};
            currentBlock = this->assignBlock(true);
            nextBlock = this->assignBlock(true);
        }
        else
        {
            lvl = new lvl4{false, file};
            currentBlock = this->assignBlock(false);
            nextBlock = this->assignBlock(false);
        }
        heavy = true;
    }
}

Block *Board ::assignBlock(bool isRandom)
{

    Block *b;
    char type = lvl->blockType(isRandom);

    if (lvl->lvlNum() == 4 && singleCount % 5 == 0 && singleCount != 0)
    {
        b = new cube(playingBoard, lvl->lvlNum(), width); // ig we need a new block to be *
        b->drop();
        // notify observers here to change display
        delete b;
    }
    else if (type == 'i' || type == 'I')
    {
        b = new iBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'j' || type == 'J')
    {
        b = new jBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'l' || type == 'L')
    {
        b = new lBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'o' || type == 'O')
    {
        b = new oBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 's' || type == 'S')
    {
        b = new sBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'z' || type == 'Z')
    {
        b = new zBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 't' || type == 'T')
    {
        b = new tBlock(playingBoard, lvl->lvlNum(), width);
    }
}

int Board ::getScore() { return score; };

bool Board ::getBlind() { return blind; };
bool Board ::getForce() { return force; };
bool Board ::getHeavy() { return heavy; };
int Board ::getLvl() { return lvl->lvlNum(); };
string Board ::getFile() { return file; };
void Board ::setBlind(bool set) { blind = set; }
void Board ::setForce(bool set) { force = set; }
void Board ::setHeavy(bool set) { heavy = set; }
void Board ::setFile(string newFile) { file = newFile; };

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
        else
        {
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
    else if (lvl->lvlNum() == 1)
    {
        tmp = new lvl2{true};
    }
    else if (lvl->lvlNum() == 2)
    {
        if (file == "")
        {
            tmp = new lvl3{true};
        }
        else
        {
            tmp = new lvl3{false, file};
        }
    }
    else
    {
        if (file == "")
        {
            tmp = new lvl4{true};
        }
        else
        {
            tmp = new lvl4{false, file};
        }
    }

    swap(lvl, tmp);
    delete tmp;
}

void Board ::sequence(string newfile)
{
    Level *tmp;
    if (lvl->lvlNum() == 0)
    {
        tmp = new lvl0{newfile, true};
    }
    else if (lvl->lvlNum() == 1)
    {
        tmp = new lvl1{true, newfile};
    }
    else if (lvl->lvlNum() == 2)
    {
        tmp = new lvl2{false, newfile};
    }
    else if (lvl->lvlNum() == 3)
    {
        tmp = new lvl3{false, file};
    }
    else
    {
        tmp = new lvl4{false, file};
    }

    swap(lvl, tmp);
    delete tmp;
}

void Board ::left() { currentBlock->left(); }
void Board ::right() { currentBlock->right(); }
void Board ::down() { currentBlock->down(); }
void Board ::drop() { currentBlock->drop(); }
void Board ::cw() { currentBlock->clockwise(); }
void Board ::ccw() { currentBlock->counterClockwise(); }

void Board ::addBlock()
{ // main calls this to add block on to board
    playingBlocks.emplace_back(currentBlock);
    // currentBlock->addBlock();

    currentBlock = nextBlock;
    if (file == "")
    {
        nextBlock = this->assignBlock(true);
    }
    else
    {
        nextBlock = this->assignBlock(false);
    }

    if (!currentBlock->canCreate())
    {
        lost = true;
        return;
    }
}

/*
void Board :: newBlock_normal()
{

    // notify observers here to change display
    if(!currentBlock -> canCreate()){
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
            currentBlock -> left();
            break;
        case RIGHT:
            currentBlock -> right();
            break;
        case DOWN:
            currentBlock -> down();
            break;
        case CLOCKWISE:
            currentBlock -> clockwise();
            break;
        case COUNTERCLOCKWISE:
            currentBlock -> counterClockwise();
            break;
        case DROP:
            currentBlock -> drop();
            break;
        }
        // notify observers here to change display
        // does block mutate playingBoard as it moves?
    }

    playingBlocks.emplace_back(currentBlock);
    currentBlock -> addBlock();

    currentBlock = nextBlock;
    if(file == ""){
        nextBlock = this -> assignBlock(true);
    }
    else{
        nextBlock = this -> assignBlock(false);
    }

}

void Board :: newBlock_heavy(){
    char type;

    if(file == ""){
        type = lvl -> blockType(true);
    }
    else{
        type = lvl -> blockType(false);
    }

    // notify observers here to change display
    if(!currentBlock -> canCreate()){
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
            currentBlock -> left();
            break;
        case RIGHT:
            currentBlock -> right();
            break;
        case DOWN:
            currentBlock -> down();
            break;
        case CLOCKWISE:
            currentBlock -> clockwise();
            break;
        case COUNTERCLOCKWISE:
            currentBlock -> counterClockwise();
            break;
        case DROP:
            currentBlock -> drop();
            break;
        }
        // notify observers here to change display
        // does block mutate playingBoard as it moves?

        currentBlock -> down();
    }

    playingBlocks.emplace_back(currentBlock);
    currentBlock -> addBlock();

    currentBlock = nextBlock;
    if(file == ""){
        nextBlock = this -> assignBlock(true);
    }
    else{
        nextBlock = this -> assignBlock(false);
    }
}

void Board :: newBlock_force() {
    char type;

    cout << "Choose a Block type: i/j/l/o/s/t/z" << endl;

    cin >> type;

    Block* b;

    if (type == 'i')
    {
        b = new iBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'j')
    {
        b = new jBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'l')
    {
        b = new lBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'o')
    {
        b = new oBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 's')
    {
        b = new sBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 'z')
    {
        b = new zBlock(playingBoard, lvl -> lvlNum(), width);
    }
    else if (type == 't')
    {
        b = new tBlock(playingBoard, lvl -> lvlNum(), width);
    }
    // notify observers here to change display
    if(!currentBlock -> canCreate()){
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
            currentBlock -> left();
            break;
        case RIGHT:
            currentBlock -> right();
            break;
        case DOWN:
            currentBlock -> down();
            break;
        case CLOCKWISE:
            currentBlock -> clockwise();
            break;
        case COUNTERCLOCKWISE:
            currentBlock -> counterClockwise();
            break;
        case DROP:
            currentBlock -> drop();
            break;
        }
        // notify observers here to change display
        // does block mutate playingBoard as it moves?

        currentBlock -> down();
    }

    playingBlocks.emplace_back(currentBlock);
    currentBlock -> addBlock();

    currentBlock = nextBlock;
    if(file == ""){
        nextBlock = this -> assignBlock(true);
    }
    else{
        nextBlock = this -> assignBlock(false);
    }
}
*/

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

        if (fullLine)
        {
            clearedlines++;
            int l = lvl->lvlNum();
            score += (++l) * (++l);

            playingBoard.erase(playingBoard.begin() + (i - 1));
            vector<char> blankLine(width, ' ');
            playingBoard.insert(playingBoard.begin(), blankLine);

            for (int k = 0; k < playingBlocks.size(); k++)
            {
                if (playingBlocks[k]->deletePos(i))
                {
                    Block *tmp = playingBlocks[k];
                    score += tmp->worth();
                    playingBlocks.erase(playingBlocks.begin() + (k - 1));
                    delete tmp;
                    k--;
                }
            }

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
    return playingBoard[row][col]; 
}

void Board::force_set(char type)
{
    Block *b;
    if (type == 'I')
    {
        b = new iBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'J')
    {
        b = new jBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'L')
    {
        b = new lBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'O')
    {
        b = new oBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'S')
    {
        b = new sBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'Z')
    {
        b = new zBlock(playingBoard, lvl->lvlNum(), width);
    }
    else if (type == 'T')
    {
        b = new tBlock(playingBoard, lvl->lvlNum(), width);
    }

    currentBlock = b;
}
/*
Block *Board::getCurrBlock()
{
    return currentBlock;
}*/
char Board::getNextBlockChar()
{
    return nextBlock->getType();
}
