#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>

class Subject;

class Observer {
 public:
  virtual void notify(std::string type, int i1, int i2) = 0;
  virtual ~Observer() = default;
};
#endif
