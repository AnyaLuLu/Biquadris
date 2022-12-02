#ifndef GDISPLAY_H
#define GDISPLAY_H

#include "observer.h"
#include "board.h"
#include "xWindow.h"

class GDisplay : public Observer
{
    Board *myBoard;
    Xwindow *myXwindow;

public:
    void notify() override;
    GDisplay(Board *myStudio, Xwindow *myXwindow);
};

#endif
