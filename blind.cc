#include "blind.h"
using namespace std;


Blind::Blind(Board* next) : Decorator{next} {}

void Blind::newBlock() {}

Blind::~Blind() {}