#include "Simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(){
  goldStudent = new BST<Student>;
  goldFaculty = new BST<Faculty>;
  // studQ = new CirQ<BST<Student>>(5);
  // facQ = new CirQ<BST<Faculty>>(5);
  advisee = new DLList<int>;
}

Simulation::~Simulation(){

}

int Simulation::displayMenu(){
  int choice;
  cout << "Please enter 1 to print out all the students and their information in ascending order of iD number." << endl;
  cout << "Please enter 2 to print out all the faculty members and their information in ascending order of iD number." << endl;
  cout << "Please enter 3 to find and display a student's information." << endl;
  cout << "Please enter 4 to find and display a faculty member's information." << endl;
  cout << "Please enter 5 to print the name and info of a student's faculty advisor." << endl;
  cout << "Please enter 6 to print the names and info of all advisees." << endl;
  cout << "Please enter 7 to add a new student." << endl;
  cout << "Please neter 8 to delete a student." << endl;
  cout << "Please enter 9 to add a faculty memebr." << endl;
  cout << "Please enter 10 to delete a faculty member." << endl;
  cout << "Please enter 11 to change a student's advisor." << endl;
  cout << "Please enter 12 to remove an advisee from a faculty member." << endl;
  cout << "Please enter 13 to rollback." << endl;
  cout << "Please enter 14 to exit." << endl;
  cin >> choice;
  return choice;
}

void Simulation::simulate(){
  int userChoice;
  userChoice = displayMenu();
  while(userChoice != 14){
    if(userChoice == 1){
      printStudnetsAscending();
    }
    else if(userChoice == 2){
      printFacultyAscending();
    }

    else if(userChoice == 3){
      int id;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      printStudentGivenID( id);
    }

    else if(userChoice == 4){
      int id;
      cout << "What is the facunty member's ID number?" << endl;
      cin >> id;
      printFacultyGivenID(id);
    }

    else if(userChoice == 5){
      int id;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      printFacGivenStudentID(id);
    }
    else if(userChoice == 6){
      int id;
      cout << "What is the faculty member's ID number?" << endl;
      cin >> id;
      printFacAdviseeList(id);
    }
    else if(userChoice == 7){
      createAndAddStudent();
    }

    else if(userChoice == 8){
      int id;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      deleteStudent(id);
    }

    else if(userChoice == 9){
      createAndAddFaculty();
    }

    else if(userChoice == 10){
      int id;
      cout << "What is the faculty member's ID number?" << endl;
      cin >> id;
      deleteFaculty(id);
    }
    else if(userChoice == 11){
      int id;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      int id2;
      cout << "What is the new faculty member's ID number?" << endl;
      cin >> id2;
      changeStudentAdvisor(id, id2);
    }

    else if(userChoice == 12){
      int id;
      int id2;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      cout << "What is the faculty member's ID number?" << endl;
      cin >> id2;
      deleteAdvisee(id, id2);
    }
    /*
    else if(userChoice == 13){
      rollBack();
    }
    */
    userChoice = displayMenu();

  }
  cout << "Program Terminated" << endl;
  //print out files
  BST<Student>* tempStudent = new BST<Student>;
  tempStudent = goldStudent;
  //studQ->add(tempStudent);

  BST<Faculty>* tempFaculty = new BST<Faculty>;
  tempFaculty = goldFaculty;
  //facQ->add(tempFaculty);


  }
//}

void Simulation::printStudnetsAscending(){
  goldStudent->printInOrder();
}

void Simulation::printFacultyAscending(){
  goldFaculty->printInOrder();
}

void Simulation::createAndAddStudent(){
  string name;
  int id;
  string level;
  int gradYear;
  string major;
  double gPA;
  int facAdvisID;
  cout << "What is the student's name? " << endl;
  cin >> name;
  cout << "What is the student's ID number?" << endl;
  cin >> id;
  cout << "What is the student's level?" << endl;
  cin >> level;
  cout << "What year does the student graduate?" << endl;
  cin >> gradYear;
  cout << "What is the student's major?" << endl;
  cin >> major;
  cout << "What id the student's GPA?" << endl;
  cin >> gPA;
  cout << "What is the student's faculty advisor's ID number?" << endl;
  cin >> facAdvisID;
  Student temp(name, id, level, gradYear, major, gPA, facAdvisID);
  goldStudent->insert(temp);
}

void Simulation::createAndAddFaculty(){
  string name;
  int id;
  string level;
  string dept;

  int tempAdvisee;

  cout << "What is the faculty member's name? " << endl;
  cin >> name;
  cout << "What is the faculty member's ID number?" << endl;
  cin >> id;
  cout << "What is the faculty member's level?" << endl;
  cin >> level;
  cout << "What department does the faculty member work in?" << endl;
  cin >> dept;
  Faculty temp(name, id, level, dept);
  cout << "Please enter all advisee ID numbers one at a time, when you are done, enter 0 :" << endl;
  while(tempAdvisee != 0){
    cin >> tempAdvisee;
    //cout << tempAdvisee << endl;
    temp.addAdvisee(tempAdvisee);
  }
  goldFaculty->insert(temp);
}
void Simulation::printStudentGivenID(int id){
  goldStudent->contains(id);
}
void Simulation::printFacultyGivenID(int id){
  goldFaculty->contains(id);
}

void Simulation::deleteStudent(int id){
  goldStudent->deleteValue(id);
}

void Simulation::deleteFaculty(int id){
  goldFaculty->deleteValue(id);
}

void Simulation::printFacGivenStudentID(int iD){
  int foundID = goldStudent->containsID(iD);
  goldFaculty->contains(foundID);
}

void Simulation::printFacAdviseeList(int iD){
  advisee = goldFaculty->containsAdviseeList(iD);
  for (int i=0; i<advisee->size(); ++i){
    int id = advisee->peek(i);
    goldStudent->contains(id);
  }
}

void Simulation::changeStudentAdvisor(int studentID, int facultyID){
  goldStudent->containsChange(studentID, facultyID);
}

void Simulation::deleteAdvisee(int studentID, int facultyID){
  advisee = goldFaculty->containsAdviseeList(facultyID);
  for (int i=0; i<advisee->size(); ++i){
    if (advisee->peek(i) == studentID){
      advisee->removeFrom(i);
    }
  }
}
