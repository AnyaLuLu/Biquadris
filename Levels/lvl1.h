#ifndef Lvl1_H
#define Lvl1_H
#include "level.h"
using namespace std;


class lvl1 : public Level{
    char blockType(bool isRandom) override;
}


#endif