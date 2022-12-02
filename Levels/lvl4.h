#ifndef Lvl4_H
#define Lvl4_H
#include "level.h"
using namespace std;


class lvl4 : public Level{
    char blockType(bool isRandom) override;
    int lvlNum();
    public:
        lvl4(bool isRandom, string file = "");
};


#endif