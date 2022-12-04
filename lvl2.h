#ifndef Lvl2_H
#define Lvl2_H
#include "level.h"
using namespace std;


class lvl2 : public Level{
    char blockType(bool isRandom) override;
    int lvlNum();
    public:
        lvl2(bool isRandom, string file = "");
};


#endif