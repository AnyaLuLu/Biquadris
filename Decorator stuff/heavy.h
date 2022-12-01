#ifndef HEAVY
#define HEAVY
#include "decorator.h"

class Heavy: public Decorator {
	public:
		Heavy(Board *next);
		void notify(Board &b) override; // not sure what this does
		~Heavy();
};

#endif