#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Level{
    string file;
    bool random;
    protected:
        vector <string> blockSequence;
    
    public:
        Level(string file = "", bool random = false);
        virtual char blockType(bool isRandom) = 0;
        virtual int lvlNum() = 0;

}


#endif