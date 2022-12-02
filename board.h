#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Levels/level.h"
#include "Blocks/block.h"
using namespace std;

class Board{
    int width, height;
    bool blind, heavy, force;
    int score;
    Level* lvl;
    string file;

    int singleCount;
    bool lost;

    protected:
        vector<vector<char>> playingBoard (height, vector<char> (width, ' '));

    
    private:
        int clearlines();
    
    public:
        void newBlock();
        bool getBlind();
        bool getHeavy();
        bool getForce();
        int getScore();
        bool checkLose();

        void levelup();
        void leveldown();

        Board(int width, int height, int newLvl, string file)();

};

#endif
