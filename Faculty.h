  
/* Sarah Caruthers and Sophia Guarnotta
2350081, 
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#ifndef FACULTY_H
#define FACULTY_H
#include "DLList.h"

using namespace std;

/*
 * Header file for Faculty class, contains necessary methods, member variables, and overloaded operators
 */
class Faculty{
public:
  Faculty();
  Faculty(string name, int iD, string level, string dept);
  ~Faculty();
  string getName();
  int getID();
  string getLevel();
  string getDepartment();
  DLList<int>* getAdviseeList();
  void setName(string name);
  void setID(int iD);
  void setLevel(string level);
  void setDepartment(string dept);
  void addAdvisee(int sID);
  void deleteAdvisee(int sID);
  string toString();
  void printInfo();
  bool isAdvisee(int sID);

  // https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
  bool operator<(Faculty &f2);
  bool operator>(Faculty &f2);
  bool operator==(Faculty &f2);

private:
  string facultyName;
  int facultyID;
  string facultyLevel;
  string facultyDepartment;
  DLList<int>* adviseeList;

}
;
#endif
