#include "level.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

Level :: Level(bool isSeeded, int seed, bool random, string file) : isSeeded{isSeeded}, seed{seed}, random{random}, file{file}, counter{0}{
    blockSequence = {};

    if((!random && file != "")){
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
   cout << "got to bottom of lvl ctor" << endl;

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
