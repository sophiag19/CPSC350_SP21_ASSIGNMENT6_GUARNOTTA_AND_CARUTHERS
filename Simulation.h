
#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "DLLStack.h"
//#include "CirQ.h"

// need to write general find node alg to find all the people
class Simulation{
public:
  Simulation();
  ~Simulation();
  void simulate();
  int displayMenu();
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
  void addStudent(string name, int id, string level, int gradYear, string major, double gpa, int facAdvisId);
  void addFaculty(string name, int id, string level, string dept);
  void changeStudentAdvisor(int studentID, int facultyID); // update student.setFacAdvisID() with new ID
  void deleteAdvisee(int studentID, int facultyID); // move method from faculty class here
  void rollBack();


private:
  BST<Student>* goldStudent;
  BST<Faculty>* goldFaculty;
  DLList<int>* advisee;
  DlStack<int>* rollStack;
  Student deletedStudent;
  Faculty deletedFaculty;
};

#endif
