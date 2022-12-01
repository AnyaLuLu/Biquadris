#ifndef FORCE
#define FORCE
#include "decorator.h"

class Force: public Decorator {
	public:
		Force(Board *next);
		void notify(Board &b) override; // not sure what this does
		~Force();
};

#endif