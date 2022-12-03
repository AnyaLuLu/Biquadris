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
    else{
        char b = blockSequence[counter];
        counter += 1;
        if (counter == length) {
            counter = 0;
        }
        return b;
    }
}

int lvl4 :: lvlNum(){return 4;};

lvl4 :: lvl4 (bool isRandom, string file = "") : Level(isRandom, file){}
    