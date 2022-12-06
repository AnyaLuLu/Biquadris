#ifndef TXTDISPLAY_H
#define TXTDISPLAY_H

#include "observer.h"
#include "board.h"
#include <iostream>

class txtDisplay : public Observer
{
    Board *Board1;
    Board *Board2;
    std::ostream &out = std::cout;

public:
    void notify(string type, int i1, int i2) override;
    txtDisplay(Board *Board1, Board *Board2);
};

#endif
