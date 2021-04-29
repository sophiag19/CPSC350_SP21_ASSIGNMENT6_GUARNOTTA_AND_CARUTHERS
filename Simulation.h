#ifndef SIMULATION_H
#define SIMULATION_H

using namespace std;
#include "Student.h"
#include "Faculty.h"
#include "BST.h"

// need to write general find node alg to find all the people
class Simualtion{
public:
  void printStudnetsAscending();
  void printFacultyAscending();
  void printStudentGivenID(goldStudent, int iD);
  void printFacultyGivenID(goldFaculty, int iD);
  void printFacGivenStudentID(goldStudent, goldFaculty); // find student, store faculty name. FInd fac in facTree and printInfo()
  void printFacAdviseeList(goldStudent, goldFaculty); // open loop on facTree, store current ID in variable, traverse goldStudent for ID and printInfo()
  void deleteStudent(int iD, goldStudent); // call removeFrom()
  void deleteFaculty(int iD, goldFaculty);
  void changeStudentAdvisor(int studentID, int facultyID, goldStudent, goldFaculty); // update student.setFacAdvisID() with new ID
  void deleteAdvisee(int sID); // move method from faculty class here

private:
  BST<Student>* goldStudent;
  BST<Faculty>* goldFaculty;

};

#endif
