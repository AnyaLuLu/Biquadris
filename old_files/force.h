#ifndef FORCE
#define FORCE
#include "decorator.h"

class Force: public Decorator {
	public:
		Force(Board *next);
		void newBlock() override;
		~Force();
};

#endif