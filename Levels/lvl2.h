#ifndef Lvl2_H
#define Lvl1_H
#include "level.h"
using namespace std;


class lvl2 : public Level{
    char blockType(bool isRandom) override;
    int lvlNum();
}


#endif