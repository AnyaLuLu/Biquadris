#include "lvl2.h"
#include <time.h>
#include <iostream>
using namespace std;

char lvl2 :: blockType(bool isRandom){
    if(isRandom && !isSeeded){
        char blockGen[7] = {'i', 'j', 'l', 'o', 's', 'z', 't'};
        srand (time(NULL));
        int index = rand() % 7;
        
        return blockGen[index];
    }
    else if (isRandom && isSeeded && blockSequence.size() != 0){
        char b = blockSequence[counter];
        counter += 1;
        if (counter == length) {
            counter = 0;
        }
        return b;
    }
    return ' ';
}

int lvl2 :: lvlNum(){return 2;};

lvl2 :: lvl2(bool isSeeded, int seed, bool isRandom, string file) : Level(isSeeded, seed, isRandom, file){
    if(isRandom && isSeeded){
        char newBlock;
        char blockGen[7] = {'i', 'j', 'l', 'o', 's', 'z', 't'};
        srand(seed);
        for(int i = 1; i <= 50; i++){
            int index = rand() % 7;
            blockSequence.emplace_back(blockGen[i]);
        }

        length = 50;
    }
    cout << "finished lvl2 ctor" << endl;
}
