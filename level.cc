#include "level.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Level :: Level(bool random, string file) : random{random}, file{file}, counter{0}{
    blockSequence = {};

    if(!random){
        ifstream myfile;
        myfile.open(file);

        char newBlock;
        if(myfile.is_open()){
            while(myfile.good()){
                myfile >> newBlock;
                blockSequence.emplace_back(newBlock);
            }
        }

        length = blockSequence.size();
    }
}

void Level :: unRandom(string newFile){
    blockSequence = {};
    ifstream myfile;
    myfile.open(newFile);

    char newBlock;
    if(myfile.is_open()){
        while(myfile.good()){
            myfile >> newBlock;
            blockSequence.emplace_back(newBlock);
        }
    }

    counter = 0;
    length = blockSequence.size();
}
