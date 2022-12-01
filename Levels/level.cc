#include "level.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Level : Level(string file = "", bool random = false) : file{file}, random{random}{
    blockSequence = {};

    if(!random){
        ifstream myfile;
        myfile.open(file);

        string newBlock;
        if(myfile.is_open()){
            while(myfile.good()){
                myfile >> newBlock;
                blockSequence.emplace_back(newBlock);
            }
        }
    }
}
