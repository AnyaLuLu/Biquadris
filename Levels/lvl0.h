#ifndef Lvl0_H
#define Lvl0_H
#include "level.h"
using namespace std;


class lvl0 : public Level{
    char blockType(bool isRandom) override;
    int lvlNum();
    public:
        lvl0(string file, bool isRandom = false);
};


#endif