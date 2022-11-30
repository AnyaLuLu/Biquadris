#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Level{
    string file;
    bool random;
    protected:
        vector <string> blockSequence;
    
    public:
        virtual string blockType(bool isRandom) = 0;
        level(string file = "", bool random = false);

}


#endif