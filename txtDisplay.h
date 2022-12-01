#ifndef TXTDISPLAY_H
#define TXTDISPLAY_H

#include "observer.h"
#include "board.h"

class txtDisplay : public Observer
{
    Board *myBoard;

public:
    void notify() override;
    txtDisplay(Board *myBoard);
};

#endif
