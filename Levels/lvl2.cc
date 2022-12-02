#include "lvl2.h"
#include <time.h>
#include "Level.h"
using namespace std;

char lvl2 :: blockType(bool isRandom){
    char blockGen[7] = {'i', 'j', 'l', 'o', 's', 'z', 't'};
    srand (time(NULL));
    int index = rand() % 7;

    return blockGen[index];
}

int lvl2 :: lvlNum(){return 2;};

lvl2 :: lvl2(bool isRandom = true) : Level{isRandom}{};