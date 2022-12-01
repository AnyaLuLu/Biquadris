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
        virtual char blockType(bool isRandom) = 0;
        Level(string file = "", bool random = false);

}


#endif