#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
  facultyName = "";
  facultyID = 0;
  facultyLevel = "";
  facultyDepartment = "";
  adviseeList = new DLList<int>;

}

Faculty::Faculty(string name, int iD, string level, string dept){
  facultyName = name;
  facultyID = iD;
  facultyLevel = level;
  facultyDepartment = dept;
  adviseeList = new DLList<int>;
  //maybe chnage to call person class
}

Faculty::~Faculty(){
  for(int i = 0; i < adviseeList->size();++i){
    adviseeList->removeBack();
  }
  delete adviseeList;
}

string Faculty::getName(){
  return facultyName;
}

int Faculty::getID(){
  return facultyID;
}

string Faculty::getLevel(){
  return facultyLevel;
}

string Faculty::getDepartment(){
  return facultyDepartment;
}

void Faculty::setName(string name){
  facultyName = name;
}

void Faculty::setID(int iD){
  facultyID = iD;
}

void Faculty::setLevel(string level){
  facultyLevel = level;
}

void Faculty::setDepartment(string dept){
  facultyDepartment = dept;
}

void Faculty::addAdvisee(int sID){
  adviseeList->insertBack(sID);
}

void Faculty::deleteAdvisee(int sID){
  for(int i = 0; i < adviseeList->size(); ++i){
    if(adviseeList->peek(i) == sID){
      adviseeList->removeFrom(i);
    }
  }
}

void Faculty::printInfo(){
  cout << "Name: " << facultyName << endl;
  cout << "ID number: " << facultyID << endl;
  cout << "Level: " << facultyLevel << endl;
  cout << "Department: " << facultyDepartment << endl;
  // FIXME: cout << adviseeList;

}

bool Faculty::isAdvisee(int sID){
  bool ret = false;
  for(int i = 0; i < adviseeList->size(); ++i){
    if(adviseeList->peek(i) == sID){
      ret = true;
    }
  }
  return ret;
}

// lines 85-104: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
bool Faculty::operator<(Faculty &f2){
  int fid = this->getID();
  int f2id = f2.getID();

  return (fid < f2id);
}

bool Faculty::operator>(Faculty &f2){
  int fid = this->getID();
  int f2id = f2.getID();

  return (fid > f2id);
}

bool Faculty::operator==(Faculty &f2){
  int fid = this->getID();
  int f2id = f2.getID();

  return (fid == f2id);
}
