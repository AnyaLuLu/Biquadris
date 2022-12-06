#include "gDisplay.h"
#include <map>

using namespace std;

map<char, int> m = {{'I', 2}, {'J', 3}, {'L', 4}, {'O', 5}, {'S', 6}, {'Z', 7}, {'T', 8}, {'*', 9}};

void updateSpace(int x, int y) {

}

void updateScore(int s1, int s2, int hiScore) {

}
void updateNext(int player, char type) {

}
void updateLevel(int player, int level) {

}
void blind(int player) {

}
void unblind(int player) {

}

void GDisplay::create() {
    x->fillRectangle(0, 0, 32*bSize+20*divider, 26*bSize+17*divider, Xwindow::Black);

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            x->fillRectangle(3*bSize + j*(bSize + divider), 4*bSize + i*(bSize + divider), bSize, bSize, Xwindow::White);
        }
    }

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            x->fillRectangle(18*bSize + 10*divider + j*(bSize + divider), 4*bSize + i*(bSize + divider), bSize, bSize, Xwindow::White);
        }
    }

    x->drawString(16*bSize+10*divider - 27, bSize - 2, "Biquadris", Xwindow::White);
    x->drawString(16*bSize+10*divider - 42, bSize + 12, "High score:", Xwindow::White);

    x->drawString(3*bSize, 4*bSize - 3, "Level:", Xwindow::White);
    x->drawString(18*bSize + 10*divider, 4*bSize - 3, "Level:", Xwindow::White);
    x->drawString(3*bSize, 4*bSize - 16, "Score:", Xwindow::White);
    x->drawString(18*bSize + 10*divider, 4*bSize - 16, "Score:", Xwindow::White);
    x->drawString(3*bSize, 23*bSize + 17*divider, "Next:", Xwindow::White);
    x->drawString(18*bSize + 10*divider, 23*bSize + 17*divider, "Next:", Xwindow::White);

    x->drawString(16*bSize+10*divider + 30, bSize + 12, "0", Xwindow::White);
    x->drawString(3*bSize + 42, 4*bSize - 3, "0", Xwindow::White);
    x->drawString(18*bSize + 10*divider + 42, 4*bSize - 3, "0", Xwindow::White);
    x->drawString(3*bSize + 42, 4*bSize - 16, "0", Xwindow::White);
    x->drawString(18*bSize + 10*divider + 42, 4*bSize - 16, "0", Xwindow::White);

    updateNext(1, Board1->getNextBlockChar()); 
    updateNext(2, Board2->getNextBlockChar()); 
}


GDisplay::GDisplay(Board *Board1, Board *Board2, Xwindow *x, int bSize, int divider) : Board1{Board1}, Board2{Board2}, x{x}, bSize{bSize}, divider{divider}
{
    Board1->attach(this);
    Board2->attach(this);
    create();
}

void GDisplay::notify(string type, int i1, int i2)
{
    if (type == "g_space") {
        updateSpace(i1, i2);

    } else if (type == "g_score") {
        updateScore(Board1->getScore(), Board2->getScore(), i1);

    } else if (type == "g_next") {
        if (i1 == 1) {
            updateNext(1, Board1->getNextBlockChar()); 
        } else if (i1 == 2) {
            updateNext(1, Board2->getNextBlockChar());
        }

    } else if (type == "g_level") {
        if (i1 == 1) {
            updateLevel(Board1->getLvl());
        } else if (i1 == 2) {
            updateLevel(Board2->getLvl()); 
        }

    } else if (type == "g_blind") {
        blind(i1);
        
    } else if (type == "g_unblind") {
        unblind(i1);
    }
}