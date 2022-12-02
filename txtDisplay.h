#ifndef TXTDISPLAY_H
#define TXTDISPLAY_H

#include "observer.h"
#include "board.h"
#include <iostream>

class txtDisplay : public Observer
{
    Board *myBoard;
    std::ostream &out = std::cout;

public:
    void notify() override;
    txtDisplay(Board *myBoard);
};

#endif
