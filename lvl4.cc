#include "lvl4.h"
#include <time.h>
#include <vector>
using namespace std;

char lvl4 :: blockType(bool isRandom){
    if(isRandom){
        char blockGen[9] = {'i', 'j', 'l', 'o', 's', 's', 'z', 'z', 't'};
        srand (time(NULL));
        int index = rand() % 12;

        return blockGen[index];
    }
    else if (blockSequence.size() != 0){
        char b = blockSequence[counter];
        counter += 1;
        if (counter == length) {
            counter = 0;
        }
        return b;
    }
    return ' ';
}

int lvl4 :: lvlNum(){return 4;};

lvl4 :: lvl4 (bool isSeeded, int seed, bool isRandom, string file) : Level(isSeeded, seed, isRandom, file){
    if(isRandom && isSeeded){
        char newBlock;
        char blockGen[9] = {'i', 'j', 'l', 'o', 's', 's', 'z', 'z', 't'};
        srand(seed);
        for(int i = 1; i <= 50; i++){
            int index = rand() % 9;
            blockSequence.emplace_back(blockGen[i]);
        }

        length = 50;
    }
};
    
