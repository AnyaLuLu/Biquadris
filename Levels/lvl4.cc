#include "lvl4.h"
#include <time.h>
#include <vector>
using namespace std;

lvl3 : blockType(bool isRandom){
    if(isRandom){
        char blockGen[9] = {'i', 'j', 'l', 'o', 's', 's', 'z', 'z', 't'};
        srand (time(NULL));
        int index = rand() % 12;

        return blockGen[index];
    }
    else{
        if(blockSequence.size() > 0){
            char b = blockSequence[0];
            blockSequence.erase(0);
            return b;
        }
    }
}
    