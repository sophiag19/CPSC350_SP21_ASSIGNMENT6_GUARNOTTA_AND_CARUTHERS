/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#ifndef SIMULATION_H
#define SIMULATION_H


#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "DLLStack.h"
#include <fstream>
#include <string>

using namespace std;

class Simulation{
public:
  Simulation();
  ~Simulation();
  void simulate(); // runs the database
  int displayMenu(); // displays menu options
  void createAndAddStudent();
  void createAndAddFaculty();
  void printStudnetsAscending();
  void printFacultyAscending();
  void printStudentGivenID(int iD);
  void printFacultyGivenID(int iD);
  void printFacGivenStudentID(int iD); // find student, store faculty name. FInd fac in facTree and printInfo()
  void printFacAdviseeList(int iD); // open loop on facTree, store current ID in variable, traverse goldStudent for ID and printInfo()
  void deleteStudent(int iD); // call removeFrom()
  void deleteFaculty(int iD);
  void readFiles();
  void addStudent(string name, int id, string level, int gradYear, string major, double gpa, int facAdvisId); // for rollback
  void addFaculty(string name, int id, string level, string dept); // for rollback 
  int changeStudentAdvisor(int studentID, int facultyID); // update student.setFacAdvisID() with new ID
  int deleteAdvisee(int studentID, int facultyID); // move method from faculty class here
  void rollBack();


private:
  BST<Student>* goldStudent; 
  BST<Faculty>* goldFaculty;
  DLList<int>* advisee; // list of advisees
  DlStack<int>* rollStack; // stack for rollback method
  Student deletedStudent; // stores the info of student that got deleted incase user decides to rollback
  Faculty deletedFaculty; // stores the info of faculty that got deleted incase user decides to rollback
  int prevFacID; // stores current fac advisor id for a student before chanign it - for rollback
  int adviseeID; // stores id of advisee to be deleted from faculty advisee list - for rollback
};

#endif
