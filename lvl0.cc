#include "lvl0.h"
#include <time.h>
#include <vector>
#include <string>
using namespace std;

char lvl0 :: blockType(bool isRandom){
    if(!isRandom && blockSequence.size() != 0){
        char b = blockSequence[counter];
        counter += 1;
        if (counter == length) {
            counter = 0;
        }
        return b;
    }
    return ' ';
}

int lvl0 :: lvlNum(){return 0;};

lvl0 :: lvl0 (string file, bool isRandom) : Level(isRandom, file){};
    