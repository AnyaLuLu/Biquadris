#include "lvl3.h"
#include <time.h>
#include <vector>
using namespace std;

char lvl3 :: blockType(bool isRandom){
    if(isRandom){
        char blockGen[9] = {'i', 'j', 'l', 'o', 's', 's', 'z', 'z', 't'};
        srand (time(NULL));
        int index = rand() % 12;

        return blockGen[index];
    }
    else{
        if(blockSequence.size() > 0){
            char b = blockSequence[0];
            blockSequence.erase(blockSequence.begin());
            return b;
        }
    }
}

int lvl3 :: lvlNum(){return 3;};

lvl3 :: lvl3 (bool isRandom, string file = "") : Level(isRandom, file){}
    