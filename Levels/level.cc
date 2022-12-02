#include "level.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Level :: Level(bool random = false, string file = "") : random{random}, file{file}{
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
    }
}
