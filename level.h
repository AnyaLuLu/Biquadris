#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Level{
    bool random;
    string file;
    protected:
        int counter;
        int length;
        vector <char> blockSequence;
    
    public:
        Level(bool random = false, string file = "");
        virtual char blockType(bool isRandom) = 0;
        virtual int lvlNum() = 0;
        virtual ~Level() = default;

        void unRandom(string newFile);

};


#endif
