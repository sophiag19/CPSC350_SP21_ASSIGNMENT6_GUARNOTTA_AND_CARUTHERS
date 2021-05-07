/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#ifndef STUDENT_H
#define STUDENT_H
#include "DLList.h"
#include <fstream>
#include "BST.h"

using namespace std;

class Student{
public:
  Student();
  Student(string name, int iD, string level, int gradYear, string major, double gpa, int facAdvisiD);
  ~Student();

  void setName(string name);
  void setID(int iD);
  void setLevel(string level);
  void setGradYear(int gradYear);
  void getMajor(string major);
  void setGpa(double gpa);
  void setFacAdvisID(int facAdvisiD);
  void printInfo();
  string toString(); // for file processing
  string getName();
  int getID();
  string getLevel();
  int getGradYear();
  string getMajor();
  double getGpa();
  int getFacAdvisiD();

  // operator overloading 
  // https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
  bool operator<(Student &s2);
  bool operator>(Student &s2);
  bool operator==(Student &s2);

private:
  // student info
  string m_name;
  int m_iD;
  string m_level;
  int m_gradYear;
  string m_major;
  double m_gpa;
  int m_facAdvisiD;
};
#endif
