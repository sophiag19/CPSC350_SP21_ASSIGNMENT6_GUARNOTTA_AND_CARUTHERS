/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

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

// defualt constructor
Student::Student(string name, int iD, string level, int gradYear, string major, double gpa, int facAdvisiD){
  m_name = name;
  m_iD = iD;
  m_level = level;
  m_gradYear = gradYear;
  m_major = major;
  m_gpa = gpa;
  m_facAdvisiD = facAdvisiD;
}

Student::~Student(){

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

void Student::printInfo(){
  cout << "ID number: " << m_iD << endl;
  cout << "Name: " << m_name << endl;
  cout << "Level: " << m_level << endl;
  cout << "Graduation Year: " << m_gradYear << endl;
  cout << "GPA: " << m_gpa << endl;
  cout << "Major: " << m_major << endl;
  cout << "Faculty Advisor ID: " << m_facAdvisiD << endl;
 }

// for files - allows us to print the student to studentTable
 string Student::toString(){
   string iD = to_string(m_iD);
   string year = to_string(m_gradYear);
   string gpa = to_string(m_gpa);
   string advisID = to_string(m_facAdvisiD);
   return (m_name + "\n" + iD +  "\n" + m_level + "\n" + year + "\n" + gpa + "\n" + m_major + "\n" + advisID + "\n");
  }

string Student::getName(){
  return m_name;
}

int Student::getID(){
  return m_iD;
}

string Student::getLevel(){
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

// operator overloading 
// lines 79-99: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
bool Student::operator<(Student &s2){
  int sid = this->getID();
  int s2id = s2.getID();

  return (sid < s2id);
}

bool Student::operator>(Student &s2){
  int sid = this->getID();
  int s2id = s2.getID();

  return (sid > s2id);
}

bool Student::operator==(Student &s2){
  int sid = this->getID();
  int s2id = s2.getID();

  return (sid == s2id);
}
