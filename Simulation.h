#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;
#include "Student.h"
#include "Faculty.h"
#include "BST.h"

// need to write general find node alg to find all the people
class Simulation{
public:
  Simulation();
  ~Simulation();
  void simulate();
  int displayMenu();
  void rollBack();
  void createAndAddStudent();
  void createAndAddFaculty();
  void printStudnetsAscending();
  void printFacultyAscending();
  void printStudentGivenID(int iD);
  void printFacultyGivenID(int iD);
  void printFacGivenStudentID(BST<Student>* goldStudent, BST<Faculty>* goldFaculty, int iD); // find student, store faculty name. FInd fac in facTree and printInfo()
  void printFacAdviseeList(BST<Student>* goldStudent, BST<Faculty>* goldFaculty, int iD); // open loop on facTree, store current ID in variable, traverse goldStudent for ID and printInfo()
  void deleteStudent(int iD); // call removeFrom()
  void deleteFaculty(int iD);
  void changeStudentAdvisor(int studentID, int facultyID, BST<Student>* goldStudent, BST<Faculty>* goldFaculty); // update student.setFacAdvisID() with new ID
  void deleteAdvisee(int sID); // move method from faculty class here

private:
  BST<Student>* goldStudent;
  BST<Faculty>* goldFaculty;
  //BST<Student>* studArr[5];
  //BST<Faculty> facArr[5];

};

#endif
