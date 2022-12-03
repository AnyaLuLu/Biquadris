#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "level.h"
#include "block.h"
#include "subject.h"
using namespace std;

class Board : public Subject{
    protected:

        int width, height;
        bool blind, heavy, force;
        int score;
        Level* lvl;
        string file;

        int singleCount;
        bool lost;

        Block* currentBlock;
        Block* nextBlock;

    public:
        vector<vector<char>> playingBoard;
        vector<Block*> playingBlocks;
        // Should be vector<vector<char>> playingBoard (height, vector<char> (width, ' '))
    
    public:
        Block* assignBlock(bool isRandom);
        Board (int width, int height, int newLvl, string file, vector<vector<char>> playingBoard);
        void newBlock();
        int getScore();
        bool checkLose();

        bool getBlind();
        bool getHeavy();
        bool getForce();
        int getLvl();
        void setBlind(bool set);
        void setHeavy(bool set);
        void setForce(bool set);

        void levelup();
        void leveldown();

        int getWidth();
        int getHeight();

        char getState(int row, int col) const override;

        int clearlines();

    private:
        void newBlock_normal();
        void newBlock_heavy();
        void newBlock_force();
};

#endif
