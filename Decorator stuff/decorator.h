#ifndef DECORATOR
#define DECORATOR
#include "board.h"


class Decorator: public AbsBoard {
        protected:
		Board *next;

        public:
                Decorator(Board *next);
                virtual ~Decorator();
};

#endif