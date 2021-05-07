/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#include "Faculty.h"

using namespace std;
/*
 * Faculty class implementation
 */

 //default constructor -- initializes member variables to arbitrary values
Faculty::Faculty(){
  facultyName = "";
  facultyID = 0;
  facultyLevel = "";
  facultyDepartment = "";
  adviseeList = new DLList<int>;

}

//overloaded constructor -- initializes member variables to parameters
Faculty::Faculty(string name, int iD, string level, string dept){
  facultyName = name;
  facultyID = iD;
  facultyLevel = level;
  facultyDepartment = dept;
  adviseeList = new DLList<int>;
}

//default destructor
Faculty::~Faculty(){//commented out to avoid segmentation fault error
  // for(int i = 0; i < adviseeList->size();++i){
  //   adviseeList->removeBack();
  // }
  //delete adviseeList;
}

/*
 * Accessors for all member variables
 */
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


/*
 * Mutators for all member variables
 */
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


/*
 * Method addAdvisee
 * adds an integer sID to the DLList of advisee ID numbers
 */
void Faculty::addAdvisee(int sID){
  adviseeList->insertFront(sID);
}

/*
 * Method toString
 * returns a string of all values of member variables and adviseeList
 * used for file processing
 */
string Faculty::toString(){
  string iD = to_string(facultyID);
  string ret = facultyName;
  ret.push_back('\n');
  ret = ret.append(to_string(facultyID));
  ret.push_back('\n');
  ret = ret.append(facultyLevel);
  ret.push_back('\n');
  ret = ret.append(facultyDepartment);
  ret.push_back('\n');
  ret.append(to_string(adviseeList->size()));
  ret.push_back('\n');
  for(int i = 0; i < adviseeList->size();++i){
    string temp = to_string(adviseeList->peek(i));
    ret = ret.append(temp);
    ret.push_back('\n');
  }
  return ret;
 }


 /*
  * Method deleteAdvisee
  * takes an integer as a parameter and searches for that int in adviseeList
  * if the values is found, it is removed from adviseeList
  */
void Faculty::deleteAdvisee(int sID){
  for(int i = 0; i < adviseeList->size(); ++i){
    if(adviseeList->peek(i) == sID){
      adviseeList->removeFrom(i);
    }
  }
}

/*
 * Method printInfo
 * prints values of member variables and adviseeList o the screen
 */
void Faculty::printInfo(){
  cout << "Name: " << facultyName << endl;
  cout << "ID number: " << facultyID << endl;
  cout << "Level: " << facultyLevel << endl;
  cout << "Department: " << facultyDepartment << endl;
  cout << "Advisee IDs: " << endl;
  for(int i = 0; i < adviseeList->size();++i){
    cout << adviseeList->peek(i) << endl;
  }

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

/*
 * Method getAdviseeList
 * returns a pointer to adviseeList
 */
DLList<int>* Faculty::getAdviseeList(){
  return adviseeList;
}

/*
 * Overloaded Comparison Operators
 * uses ID numbers to compare objects
 */
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
