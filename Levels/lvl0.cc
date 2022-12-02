#include "lvl0.h"
#include <time.h>
#include <vector>
#include <string>
using namespace std;

char lvl0 :: blockType(bool isRandom){
    if(!isRandom){
        if(blockSequence.size() > 0){
            char b = blockSequence[0];
            blockSequence.erase(blockSequence.begin());
            return b;
        }
    }
    return ' ';
}

int lvl0 :: lvlNum(){return 0;};

lvl0 :: lvl0 (string file, bool isRandom = false) : Level(isRandom, file){};
    