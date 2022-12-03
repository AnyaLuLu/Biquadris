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

    
    private:
        Block* assignBlock(bool isRandom);
    
    public:
        Board (int width, int height, int newLvl, string file, vector<vector<char>> playingBoard);
        virtual void newBlock();
        int getScore();
        bool checkLose();

        bool getBlind();
        bool getHeavy();
        bool getForce();
        void setBlind(bool set);
        void setHeavy(bool set);
        void setForce(bool set);

        void levelup();
        void leveldown();

        int getWidth();
        int getHeight();

        char getState(int row, int col) const override;

        int clearlines();
};

#endif
