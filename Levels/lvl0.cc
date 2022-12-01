#include "lvl3.h"
#include <time.h>
#include <vector>
using namespace std;

lvl3 : blockType(bool isRandom){
    if(!isRandom){
        if(blockSequence.size() > 0){
            char b = blockSequence[0];
            blockSequence.erase(0);
            return b;
        }
    }
    return '';
}

lvl1 : int lvlNum(){return 0};
    