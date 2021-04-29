#ifndef STUDENT_H
#define STUDENT_H
#include "DLList.h"
#include "Person.h"

using namespace std;

class Student: public Person{
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

  string getName();
  int getID();
  string setLevel();
  int getGradYear();
  string getMajor();
  double getGpa();
  int getFacAdvisiD();

  // https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
  bool operator<(Student &s2);
  bool operator>(Student &s2);
  bool operator==(Student &s2);

private:
  string m_name;
  int m_iD;
  string m_level;
  int m_gradYear;
  string m_major;
  double m_gpa;
  int m_facAdvisiD;
};
#endif
