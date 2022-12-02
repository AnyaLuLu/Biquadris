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
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum Op {LEFT, RIGHT, DOWN, CLOCKWISE, COUNTERCLOCKWISE, DROP, LEVEL_UP, LEVEL_DOWN, NO_RANDOM, RANDOM, BLOCK, RESTART, SEQUENCE};

Op convertOp(string opStr) {
    vector<string> commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "block", "restart", "sequence"};

    for (int i = 0; i < commands.size(); ++i) {
        if (opStr.size() <= commands[i].size() && opStr == commands[i].substr(0, opStr.size())) {
            return i;
        }
    }
} // convertOp




Board :: Board(int width, int height, int newLvl, string file)() : width{width}, height{height}, blind{false}, heavy{false}, force{false}, score{0}, file{file}, singleCount{0}, lost{false}{
    if(newLvl <= 0){
        lvl = new lvl0{file, false};
    }
    else if(newLvl == 1){
        lvl = new lvl1{true};
    }
    else if(newLvl == 2){
        lvl = new lvl2{true};
    }
    else if(newLvl == 3){
        if(file == ""){
            lvl = new lvl3{true};
        }
        else{
            lvl = new lvl3{file, false};
        }
    }
    else{
        if(file == ""){
            lvl = new lvl4{true};
        }
        else{
            lvl = new lvl4{file, false};
        }
    }
}


bool Board :: getBlind(){return blind;};
bool Board :: getForce(){return force;};
bool Board:: getHeavy(){return heavy;};
int Board :: getScore(){return score;};

bool Board :: checkLose(){
    if(lost){return true};

    for(int i = 0; i < width; i++){
        if(playingBoard[0][i] != ' '){
            return true;
        }
    }

};

void Board :: leveldown(){
    if(lvl.lvlNum == 0){
        cout << "Minimum level is 0, you cannot go any lower";
        return;
    }
    else if(lvl.lvlNum == 1){
        Level* tmp = new lvl0{file, false};
    }
    else if(lvl.lvlNum == 2){
        Level* tmp = new lvl1{true};
    }
    else if(lvl.lvlNum == 3){
        Level* tmp = new lvl2{true};
    }
    else if(lvl.lvlNum == 4){
        Level* tmp;
        if(file == ""){
            Level* tmp = new lvl3{true};
        }
        else{
            Level* tmp = new lvl3{file, false};
        }
    }

    swap(lvl, tmp);
    delete tmp;
}


void Board :: levelup(){
    if(lvl.lvlNum == 4){
        cout << "Max level is 4, you cannot go any higher";
        return;
    }
    else if(lvl.lvlNum == 0){
        Level* tmp = new lvl1{true};
    }
    else if(lvl.lvlNum == 1){
        Level* tmp = new lvl2{true};
    }
    else if(lvl.lvlNum == 2){
        Level* tmp;
        if(file == ""){
            Level* tmp = new lvl3{true};
        }
        else{
            Level* tmp = new lvl3{file, false};
        }
    }
    else{
        Level* tmp;
        if(file == ""){
            Level* tmp = new lvl4{true};
        }
        else{
            Level* tmp = new lvl4{file, false};
        }
    }

    swap(lvl, tmp);
    delete tmp;
}

void Block :: newBlock(){
    char type = lvl.blockType();
    Block *b;
    if(singleCount % 5 == 0 && singleCount != 0){
        b = new starBlock(this); // ig we need a new block to be *
        b.drop();
        // notify observers here to change display
        delete b;
    }
    else if(type == 'i'){
        b = new iBlock(this);
    }
    else if(type == 'j'){
        b = new jBlock(this);
    }
    else if(type == 'l'){
        b = new lBlock(this);
    }
    else if(type == 'o'){
        b = new oBlock(this);
    }
    else if(type == 's'){
        b = new sBlock(this);
    }
    else if(type == 'z'){
        b = new zBlock(this);
    }
    else if(type == 't'){
        b = new tBlock(this);
    }
    
    // notify observers here to change display
    if(!b.canCreate()){
        lost = true;
        return;
    }

    cout << "Command: ";
    string command;

    while(cin >> command){
        Op op = convertOp(command);

        switch( op ) {
            case LEFT: 
                b -> left();
                break;
            case RIGHT:
                b -> right();
            	break;
            case DOWN: 
                b -> down();
                break;
            case CLOCKWISE: 
                b -> clockwise();
                break;				
            case COUNTERCLOCKWISE:
                b -> counterClockwise();
                break;
            case DROP: 
                b -> drop();
                break;
            
        }
        // notify observers here to change display
        // does block mutate playingBoard as it moves?
    }

    delete b;
}


int Board :: clearlines(){
    int clearedlines = 0;

    for(int i = 0; i < height; i++){
        bool fullLine = true;
        for(int j = 0; j < width; j++){
            if(playingBoard[i][j] == ' '){
                fullLine = false;
            }
        }

        if(lineclear){
            clearedlines++;
            playingBoard.erase(i);
            vector<char> blankLine(width, ' ');
            playingBoard.push_front(blankLine);

            // notify observers to change display
        }
    }
}
