#ifndef Lvl1_H
#define Lvl1_H
#include "level.h"
using namespace std;


class lvl0 : public Level{
    char blockType(bool isRandom) override;
    int lvlNum();
}


#endif