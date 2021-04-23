#include "Student.h"

Student::Student(){
  m_name = "";
  m_iD = 0;
  m_level = "";
  m_gradYear = 0;
  m_major = "";
  m_gpa = 0.0;
  m_facAdvisiD = 0;
}

Student::Student(string name, int iD; string level, int gradYear; string major; double gpa; int facAdvisiD){
  m_name = name;
  m_iD = iD;
  m_level = level;
  m_gradYear = gradYear;
  m_major = major;
  m_gpa = gpa;
  m_facAdvisiD = facAdvisiD;
}

Student::~Student(){
//FIXME
}

void Student::setName(string name){
  m_name = name;
}

void Student::setID(int iD){
  m_iD = iD;
}

void Student::setLevel(string level){
  m_level = level;
}
void Student::setGradYear(int gradYear){
  m_gradYear = gradYear;
}

void Student::getMajor(string major){
  m_major = major;
}
void Student::setGpa(double gpa){
  m_gpa = gpa;
}
void Student::setFacAdvisID(int facAdvisiD){
  m_facAdvisiD = facAdvisiD;
}

string Student::getName(){
  return m_name;
}

int Student::getID(){
  return m_iD;
}

string Student::setLevel(){
  return m_level;
}

int Student::getGradYear(){
  return m_gradYear;
}

string Student::getMajor(){
  return m_major;
}
double Student::getGpa(){
  return m_gpa;
}

int Student::getFacAdvisiD(){
  return m_facAdvisiD;
}
