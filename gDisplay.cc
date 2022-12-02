#include "gDisplay.h"

GDisplay::GDisplay(Board *myStudio, Xwindow *myXwindow) : myBoard{myBoard}, myXwindow{myXwindow}
{
    myBoard->attach(this);
}

void GDisplay::notify()
{
    char character;
    int colour;
    for (int i = 0; i < myBoard->getHeight(); ++i)
    {
        for (int j = 0; j < myBoard->getWidth(); ++j)
        {
            character = myBoard->getState(i, j);
            if (' ' == character)
            {
                colour = 0;
            }
            else if ('*' == character)
            {
                colour = 1;
            }
            else if ('i' == character)
            {
                colour = 2;
            }
            else if ('j' == character)
            {
                colour = 3;
            }
            else if ('l' == character)
            {
                colour = 4;
            }
            else if ('o' == character)
            {
                colour = 5;
            }
            else if ('s' == character)
            {
                colour = 6;
            }
            else if ('t' == character)
            {
                colour = 7;
            }
            else if ('z' == character)
            {
                colour = 8;
            }
            myXwindow->fillRectangle((j * 10), (i * 10), 10, 10, colour);
        }
    }
}