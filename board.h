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

        void left();
        void right();
        void down();
        void drop();
        void cw();
        void ccw();

        void addBlock();


    private:
        void left_norm();
        void right_norm();
        void down_norm();
        void drop_norm();
        void cw_norm();
        void ccw_norm();
        /*
        void newBlock_normal();
        void newBlock_heavy();
        void newBlock_force();
        */
};

#endif
