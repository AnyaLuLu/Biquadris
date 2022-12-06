#include "lvl1.h"
#include <time.h>
using namespace std;

char lvl1 :: blockType(bool isRandom){
    if(isRandom && !isSeeded){
        char blockGen[12] = {'i', 'i', 'j', 'j', 'l', 'l', 'o', 'o', 's', 'z', 't', 't'};
        srand (time(NULL));
        int index = rand() % 12;

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

int lvl1 :: lvlNum(){return 1;}

lvl1 :: lvl1 (bool isSeeded, int seed, bool isRandom, string file) : Level(isSeeded, seed, isRandom, file){
    if(isRandom && isSeeded){
        char newBlock;
        char blockGen[12] = {'i', 'i', 'j', 'j', 'l', 'l', 'o', 'o', 's', 'z', 't', 't'};
        srand(seed);
        for(int i = 1; i <= 50; i++){
            int index = rand() % 12;
            blockSequence.emplace_back(blockGen[i]);
        }

        length = 50;
    }
}
