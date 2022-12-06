#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "level.h"
#include "block.h"
#include "subject.h"

class Board : public Subject{
    protected:

        int width, height;
        bool blind, heavy, force;
        int score;
        Level* lvl;
        std::string file;

        int singleCount;
        bool lost;

        Block* currentBlock;
        Block* nextBlock;

    public:
        std::vector<std::vector<char>> playingBoard;
        std::vector<Block*> playingBlocks;
        // Should be vector<vector<char>> playingBoard (height, vector<char> (width, ' '))
    
    public:
        Block* assignBlock(bool isRandom);
        Board (int width, int height, int newLvl, std::string file, std::vector<std::vector<char>> playingBoard);
        int getScore();
        bool checkLose();

        bool getBlind();
        bool getHeavy();
        bool getForce();
        int getLvl();
        std::string getFile();
        void setBlind(bool set);
        void setHeavy(bool set);
        void setForce(bool set);
        void setFile(std::string newFile);

        void levelup();
        void leveldown();
        //void sequence(string newfile);

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

        void force_set(char type);

        //Block *getCurrBlock();
        char getNextBlockChar();
};

#endif
