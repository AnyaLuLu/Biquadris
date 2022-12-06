#ifndef GDISPLAY_H
#define GDISPLAY_H

#include "observer.h"
#include "board.h"
#include "xWindow.h"

class GDisplay : public Observer
{
    Board *Board1;
    Board *Board2;
    Xwindow *x;
    int bSize;
    int divider;

public:
    void notify(std::string type, int i1, int i2) override;
    GDisplay(Board *Board1, Board *Board2, Xwindow *x, int bSize, int divider);

private:
    void create();
    void updateSpace(int x, int y);
    void updateSpaceBlank(int x, int y);
    void updateScore(int s1, int s2, int hiScore);
    void updateNext(int player, char type);
    void updateLevel(int player, int level);
    void blind(int player);
    void unblind(int player);
};

#endif
