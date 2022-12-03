#ifndef HEAVY
#define HEAVY
#include "decorator.h"

class Heavy: public Decorator {
	public:
		Heavy(Board *next);
		void newBlock() override;
		~Heavy();
};

#endif