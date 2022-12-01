#include "lvl2.h"
#include <time.h>
using namespace std;

lvl2 : blockType(bool isRandom){
    char blockGen[7] = {'i', 'j', 'l', 'o', 's', 'z', 't'};
    srand (time(NULL));
    int index = rand() % 7;

    return blockGen[index];
}

lvl2 : int lvlNum(){return 2};