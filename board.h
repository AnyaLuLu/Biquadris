#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Levels/level.h"
#include "Blocks/block.h"
#include "subject.h"
using namespace std;

class Board : public Subject{
    int width, height;
    bool blind, heavy, force;
    int score;
    Level* lvl;
    string file;

    int singleCount;
    bool lost;

    public:
        vector<vector<char>> playingBoard;
        // Should be vector<vector<char>> playingBoard (height, vector<char> (width, ' '))

    
    private:
        int clearlines();
    
    public:
        Board (int width, int height, int newLvl, string file, vector<vector<char>> playingBoard);
        void newBlock();
        bool getBlind();
        bool getHeavy();
        bool getForce();
        int getScore();
        bool checkLose();

        void levelup();
        void leveldown();

        int getWidth();
        int getHeight();

        char getState(int row, int col) const override;
};

#endif
