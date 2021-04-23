#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
#include "DLList.h"

using namespace std;

class Faculty: public Person{
public:
  Faculty();
  Faculty(string name, int iD, string level, string dept);
  ~Faculty();
  string getName();
  int getID();
  string getLevel();
  string getDepartment();
  void setName(string name);
  void setID(int iD);
  void setLevel(string level);
  void setDepartment(string dept);
  void addAdvisee(int sID);
  void deleteAdvisee(int sID);
  bool isAdvisee(int sID);
private:
  string facultyName;
  int facultyID;
  string facultyLevel;
  string facultyDepartment;
  DLList<int>* adviseeList;

}
;
#endif
