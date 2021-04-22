#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
//#include "Student.h"
//#include "Faculty.h"

using namespace std;

class Person{
public:
  Person() {}
  virtual ~Person() {}
  virtual string getName() = 0;
  virtual int getID() = 0;
  virtual string getLevel() = 0;
  virtual void setName(string name) = 0;
  virtual void setID(int iD)  = 0;
  virtual void setLevel(string level) = 0;
private://do we need these?
  string name;
  int iD;
  //operators here or in child classes

}
;
#endif
