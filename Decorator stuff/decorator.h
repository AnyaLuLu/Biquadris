#ifndef DECORATOR
#define DECORATOR
#include "board.h"


class Decorator: public Board {
        protected:
		Board *next;

        public:
                Decorator(Board *next);
                virtual ~Decorator();
};

#endif