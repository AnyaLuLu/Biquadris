#ifndef Lvl3_H
#define Lvl3_H
#include "level.h"
#include <vector>
using namespace std;


class lvl3 : public Level{
    char blockType(bool isRandom) override;
    int lvlNum();
    public:
        lvl3(bool isRandom, string file = "");
};


#endif