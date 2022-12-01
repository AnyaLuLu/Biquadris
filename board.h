#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Board{
    int width, height;
    bool blind, heavy, force;
    int score;
    Level lvl;

    protected:
        char playingBoard [width] [height];
    
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

        Board(int width, int height, int newLvl)();

}

#endif