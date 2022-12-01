#ifndef BLIND
#define BLIND
#include "decorator.h"

class Blind: public Decorator {
	public:
		Blind(Board *next);
		void notify(Board &b) override; // not sure what this does
		~Blind();
};

#endif