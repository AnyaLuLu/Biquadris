#ifndef BLIND
#define BLIND
#include "decorator.h"

class Blind: public Decorator {
	public:
		Blind(Board *next);
		void newBlock() override;
		~Blind();
};

#endif