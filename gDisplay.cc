#include "gDisplay.h"
#include <map>
#include <sstream>

using namespace std;

map<char, int> m = {{' ', 0}, {'I', 2}, {'J', 3}, {'L', 4}, {'O', 5}, {'S', 6}, {'Z', 7}, {'T', 8}, {'*', 9}};

void GDisplay::updateSpace(int row, int col) {
    if (col > 10) {
        col -= 11;
        char val = Board2->getState(row, col);
        int colour = m[val];

        if (!(Board2->getBlind() && row >= 2 && col >= 2 && row < 12 && col < 9)) {
            x->fillRectangle(18*bSize + 10*divider + col*(bSize + divider), 4*bSize + row*(bSize + divider), bSize, bSize, colour);
        }
    } else {
        char val = Board1->getState(row, col);
        int colour = m[val];

        if (!(Board1->getBlind() && row >= 2 && col >= 2 && row < 12 && col < 9)) {
            x->fillRectangle(3*bSize + col*(bSize + divider), 4*bSize + row*(bSize + divider), bSize, bSize, colour);
        } 
    }
}

void GDisplay::updateSpaceBlank(int row, int col) {
    int colour = Xwindow::White;

    if (col > 10) {
        col -= 11;
        if (!(Board2->getBlind() && row >= 2 && col >= 2 && row < 12 && col < 9)) {
            x->fillRectangle(18*bSize + 10*divider + col*(bSize + divider), 4*bSize + row*(bSize + divider), bSize, bSize, colour);
        }
    } else {
        if (!(Board1->getBlind() && row >= 2 && col >= 2 && row < 12 && col < 9)) {
            x->fillRectangle(3*bSize + col*(bSize + divider), 4*bSize + row*(bSize + divider), bSize, bSize, colour);
        }
    }
}

void GDisplay::updateScore(int s1, int s2, int hiScore) {
    ostringstream sock1;
    ostringstream sock2;
    ostringstream sockhi;
    sock1 << s1;
    sock2 << s2;
    sockhi << hiScore;

    x->fillRectangle(16*bSize+10*divider + 30, bSize + 2, 20, 10, Xwindow::Black);
    x->fillRectangle(3*bSize + 42, 4*bSize - 26, 20, 10, Xwindow::Black);
    x->fillRectangle(18*bSize + 10*divider + 42, 4*bSize - 26, 20, 10, Xwindow::Black);

    x->drawString(16*bSize+10*divider + 30, bSize + 12, sockhi.str(), Xwindow::White);
    x->drawString(3*bSize + 42, 4*bSize - 16, sock1.str(), Xwindow::White);
    x->drawString(18*bSize + 10*divider + 42, 4*bSize - 16, sock2.str(), Xwindow::White);
}
void GDisplay::updateNext(int player, char type) {
    
    int colour = m[type];

    int lShift = 0;
    if (player == 2) {
        lShift += 15*bSize + 10*divider;
    }

    x->fillRectangle(8*bSize+5*divider + lShift, 23*bSize + 17*divider, 4*bSize + 3*divider, 2*bSize + divider, Xwindow::Black);

    if (type == 'I') {
        x->fillRectangle(8*bSize+5*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(10*bSize+7*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(11*bSize+8*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
    } else if (type == 'J') {
        x->fillRectangle(8*bSize+5*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(10*bSize+7*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(8*bSize+5*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
    } else if (type == 'L') {
        x->fillRectangle(10*bSize+7*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(10*bSize+7*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(8*bSize+5*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
    } else if (type == 'O') {
        x->fillRectangle(8*bSize+5*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(8*bSize+5*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
    } else if (type == 'S') {
        x->fillRectangle(10*bSize+7*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(8*bSize+5*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
    } else if (type == 'T') {
        x->fillRectangle(10*bSize+7*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(8*bSize+5*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
    } else if (type == 'Z') {
        x->fillRectangle(10*bSize+7*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 24*bSize + 18*divider, bSize, bSize, colour);
        x->fillRectangle(9*bSize+6*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
        x->fillRectangle(8*bSize+5*divider + lShift, 23*bSize + 17*divider, bSize, bSize, colour);
    }

    if (player == 1) {
        updateSpace(3, 0);
        updateSpace(3, 1);
        updateSpace(3, 2);
        updateSpace(3, 3);
        updateSpace(2, 0);
        updateSpace(2, 1);
        updateSpace(2, 2);
    } else if (player == 2) {
        updateSpace(3, 11);
        updateSpace(3, 12);
        updateSpace(3, 13);
        updateSpace(3, 14);
        updateSpace(2, 11);
        updateSpace(2, 12);
        updateSpace(2, 13);
    }
}
void GDisplay::updateLevel(int player, int level) {
    ostringstream sockl;
    sockl << level;


    if (player == 1) {
        x->fillRectangle(3*bSize + 42, 4*bSize - 13, 20, 10, Xwindow::Black);
        x->drawString(3*bSize + 42, 4*bSize - 3, sockl.str(), Xwindow::White);
    } else {
        x->fillRectangle(18*bSize + 10*divider + 42, 4*bSize - 13, 20, 10, Xwindow::Black);
        x->drawString(18*bSize + 10*divider + 42, 4*bSize - 3, sockl.str(), Xwindow::White);
    }
}
void GDisplay::blind(int player) {
    if (player == 1) {
        x->fillRectangle(5*bSize + 2*divider, 6*bSize + 2*divider, 7*bSize + 6*divider, 10*bSize + 9*divider, Xwindow::Black);
    } else {
        x->fillRectangle(20*bSize + 12*divider, 6*bSize + 2*divider, 7*bSize + 6*divider, 10*bSize + 9*divider, Xwindow::Black);
    }
}
void GDisplay::unblind(int player) {
    if (player == 1) {
        for (int i = 2; i < 12; i++) {
            for (int j = 2; j < 9; j++) {
                updateSpace(i, j);
            }
        }
    } else {
        for (int i = 13; i < 23; i++) {
            for (int j = 2; j < 9; j++) {
                updateSpace(i, j);
            }
        }
    }
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

    } else if (type == "g_blank") {
        updateSpaceBlank(i1, i2);

    } else if (type == "g_score") {
        updateScore(Board1->getScore(), Board2->getScore(), i1);

    } else if (type == "g_next") {
        if (i1 == 1) {
            updateNext(1, Board1->getNextBlockChar()); 
        } else if (i1 == 2) {
            updateNext(2, Board2->getNextBlockChar());
        }

    } else if (type == "g_level") {
        if (i1 == 1) {
            updateLevel(1, Board1->getLvl());
        } else if (i1 == 2) {
            updateLevel(2, Board2->getLvl()); 
        }

    } else if (type == "g_blind") {
        blind(i1);
        
    } else if (type == "g_unblind") {
        unblind(i1);
    }
}