#include "board.h"
#include "Levels/level.h"
#include "Levels/lvl0.h"
#include "Blocks/block.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Board : Board(int width, int height, int newLvl)() : width{width}, height{height}, blind{false}, heavy{false}, force{false}, score{0}, playingBoard{{{0}}}{
    if(newLvl == 0){
        lvl0
        lvl = 
    }
}