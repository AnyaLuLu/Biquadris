#include "blind.h"
using namespace std;


Blind::Blind(Board* next) : Decorator{next} {}

void Blind::notify(Board &b) {
	// change board somehow
}

Blind::~Blind() {}