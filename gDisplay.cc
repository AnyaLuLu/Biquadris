#include "gDisplay.h"

GDisplay::GDisplay(Board *myStudio, Xwindow *myXwindow) : myBoard{myBoard}, myXwindow{myXwindow}
{
    myBoard->attach(this);
}

void GDisplay::notify()
{
    // implement this
}