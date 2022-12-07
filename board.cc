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

Board ::Board(int width, int height, int newLvl, string file, vector<vector<char>> playingBoard, bool isSeeded, int seed) : width{width}, height{height}, blind{false}, heavy{false}, force{false}, score{0}, file{file}, singleCount{0}, lost{false}, isSeeded{isSeeded}, seed{seed}, playingBoard{playingBoard}, playingBlocks{}
{

    /**** If there is no file associated with the lvl, please input empty string for file *****/
    if (newLvl <= 0)
    {
        lvl = new lvl0{file, false};
        currentBlock = this->assignBlock(false);
        nextBlock = this->assignBlock(false);
        //std::cerr << "I've been assigned" << std::endl;
    }
    else if (newLvl == 1)
    {
        lvl = new lvl1{isSeeded, seed, true};
        currentBlock = this->assignBlock(true);
        nextBlock = this->assignBlock(true);
    }
    else if (newLvl == 2)
    {
        lvl = new lvl2{isSeeded, seed, true};
        currentBlock = this->assignBlock(true);
        nextBlock = this->assignBlock(true);
    }
    else if (newLvl == 3)
    {
        if (file == "")
        {
            lvl = new lvl3{isSeeded, seed, true};
            currentBlock = this->assignBlock(true);
            nextBlock = this->assignBlock(true);
        }
        else
        {
            lvl = new lvl3{false, 0, false, file};
            currentBlock = this->assignBlock(false);
            nextBlock = this->assignBlock(false);
        }
        heavy = true;
    }
    else
    {
        if (file == "")
        {
            lvl = new lvl4{isSeeded, seed, true};
            currentBlock = this->assignBlock(true);
            nextBlock = this->assignBlock(true);
        }
        else
        {
            lvl = new lvl4{false, 0, false, file};
            currentBlock = this->assignBlock(false);
            nextBlock = this->assignBlock(false);
        }
        heavy = true;
    }
    currentBlock -> addBlock();
}

Board :: ~Board(){
    delete lvl;
    delete currentBlock;
    delete nextBlock;
    for(auto b : playingBlocks){
        delete b;
    }
    playingBlocks.clear();
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
	//cout << "A I block has been assigned" << endl;
    }
    else if (type == 'j' || type == 'J')
    {
        b = new jBlock(playingBoard, lvl->lvlNum(), width);
	//cout << "A J block has been assigned" << endl;
    }
    else if (type == 'l' || type == 'L')
    {
        b = new lBlock(playingBoard, lvl->lvlNum(), width);
	//cout << "A L block has been assigned" << endl;
    }
    else if (type == 'o' || type == 'O')
    {
        b = new oBlock(playingBoard, lvl->lvlNum(), width);
	//cout << "A O block has been assigned" << endl;
    }
    else if (type == 's' || type == 'S')
    {
        b = new sBlock(playingBoard, lvl->lvlNum(), width);
	//cout << "A S block has been assigned" << endl;
    }
    else if (type == 'z' || type == 'Z')
    {
        b = new zBlock(playingBoard, lvl->lvlNum(), width);
	//cout << "A Z block has been assigned" << endl;
    }
    else if (type == 't' || type == 'T')
    {
        b = new tBlock(playingBoard, lvl->lvlNum(), width);
	//cout << "A T block has been assigned" << endl;
    }
    
    //cout << "If block's type was not specified, we did not assign properly" << endl;

    return b;
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
void Board ::setFile(string newFile){
    if(file == "" && newFile == ""){
        std:: cout << "Blocks are already being generated randomly" << endl;
        return;
    }
    else if(file == newFile){
        std:: cout << "That file is alreay in use" << endl;
        return;
    }
    else if(newFile != ""){
        // level was random, now we need to generate a new vector of blocks
        lvl -> unRandom(newFile);
    }
    file = newFile;
};

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
        cout << "Changed to level 0" << endl;
        tmp = new lvl0{file, false};
    }
    else if (lvl->lvlNum() == 2)
    {
        cout << "Changed to level 1" << endl;
        tmp = new lvl1{true};
    }
    else if (lvl->lvlNum() == 3)
    {
        cout << "Changed to level 2" << endl;
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
            tmp = new lvl3{false, 0, false, file};
        }
        cout << "Changed to level 3" << endl;
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
        cout << "Changed to level 1" << endl;
        tmp = new lvl1{true};
    }
    else if (lvl->lvlNum() == 1)
    {
        cout << "Changed to level 2" << endl;
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
            tmp = new lvl3{false, 0, false, file};
        }
        cout << "Changed to level 3" << endl;
    }
    else
    {
        if (file == "")
        {
            tmp = new lvl4{true};
        }
        else
        {
            tmp = new lvl4{false, 0, false, file};
        }
        cout << "Changed to level 4" << endl;
    }

    swap(lvl, tmp);
    delete tmp;
}

/*
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
*/

void Board ::undraw(int player) {
    int shift = 0;
    if (player == 2) {
        shift = 11;
    }

    std::vector<std::pair<int, int>> pos = currentBlock->getPos();
    for (int i = 0; i < pos.size(); ++i) {
        notifyObservers("g_blank", pos[i].first, pos[i].second + shift);
    }
}
void Board ::draw(int player) {
    std::vector<std::pair<int, int>> pos = currentBlock->getPos();
    int shift = 0;
    if (player == 2) {
        shift = 11;
    }

    for (int i = 0; i < pos.size(); ++i) {
        cerr << pos[i].first << " and " << pos[i].second << endl;
        notifyObservers("g_space", pos[i].first, pos[i].second + shift);
    }
}

void Board ::left() { currentBlock->left(); cout << "block -> left() works"<< endl;}
void Board ::right() { currentBlock->right();}
bool Board ::down() { return currentBlock->down(); }
void Board ::drop() {currentBlock->drop();}
void Board ::cw() { currentBlock->clockwise(); }
void Board ::ccw() { currentBlock->counterClockwise();}

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
    currentBlock -> addBlock();
}



int Board ::clearlines(int player)
{
    // change score
    int clearedlines = 0;
    int topLine = 0;
    int botLine = 0;
    bool topSet = false;

    for (int i = 0; i < height; i++)
    {
        bool fullLine = true;
        
        for (int j = 0; j < width; j++)
        {
            if (playingBoard[i][j] == ' ')
            {
                fullLine = false;
            }
            if (playingBoard[i][j] != ' ' && !topSet)
            {
                topSet = true;
                topLine = i;
            }
        }

        if (fullLine)
        {
            botLine = i;

            clearedlines++;

            playingBoard.erase(playingBoard.begin() + i);
            vector<char> blankLine(width, ' ');
            playingBoard.insert(playingBoard.begin(), blankLine);

            for (int k = 0; k < playingBlocks.size(); k++)
            {
                if (playingBlocks[k]->deletePos(i))
                {
                    Block *tmp = playingBlocks[k];
                    score += tmp->worth();
                    playingBlocks.erase(playingBlocks.begin() + k);
                    delete tmp;
                    k--;
			        std::cout << "a block has been deleted on line " << i <<  std::endl;
                }
            }

            i -= 1;
        }

    }

    int shift = 0;
    if (player == 2) {
        shift = 11;
    }

    for (int i = topLine; i <= botLine; i++) {
        for (int j = 0; j < width; j++) {
            notifyObservers("g_space", i, j + shift);
        }
    }

    int l = lvl->lvlNum();
    //std:: cout <<(l + clearedlines) * (l + clearedlines) << endl;
    if(clearedlines > 0){
        score += (l + clearedlines) * (l + clearedlines );
        std::cout << "score is updating here dunno y clearedlines > 0" << std::endl;
    }
    

   return clearedlines;
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
char Board::getNextBlockChar(){return nextBlock->getType();}
