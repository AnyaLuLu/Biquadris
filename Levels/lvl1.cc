#include "lvl1.h"
#include <time.h>
using namespace std;

lvl1 : blockType(bool isRandom){
    char blockGen[12] = {'i', 'i', 'j', 'j', 'l', 'l', 'o', 'o', 's', 'z', 't', 't'};
    srand (time(NULL));
    int index = rand() % 12;

    return blockGen[index];
}