/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#include "Simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(){
  goldStudent = new BST<Student>;
  goldFaculty = new BST<Faculty>;
  advisee = new DLList<int>;
  rollStack = new DlStack<int>;
  deletedStudent = Student(); // stores deleted student for rollback method
  deletedFaculty = Faculty(); // stores deleted faculty member for rollback method
  prevFacID = 0; // stores a student's current faculty advisor id before changing the faculty advisor id for rollback method
  adviseeID = 0; // store deleted advisee id for rollback method
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
  readFiles();
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
      rollStack->push(7);
    }

    else if(userChoice == 8){
      int id;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      deleteStudent(id);
      rollStack->push(8);
    }

    else if(userChoice == 9){
      createAndAddFaculty();
      rollStack->push(9);
    }

    else if(userChoice == 10){
      int id;
      cout << "What is the faculty member's ID number?" << endl;
      cin >> id;
      deleteFaculty(id);
      rollStack->push(10);
    }
    else if(userChoice == 11){
      int id;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      int id2;
      cout << "What is the new faculty member's ID number?" << endl;
      cin >> id2;
      prevFacID = changeStudentAdvisor(id, id2);
      rollStack->push(id);
      rollStack->push(prevFacID);
      rollStack->push(11);
    }

    else if(userChoice == 12){
      int id;
      int id2;
      cout << "What is the student's ID number?" << endl;
      cin >> id;
      cout << "What is the faculty member's ID number?" << endl;
      cin >> id2;
      adviseeID = deleteAdvisee(id, id2);
      rollStack->push(id2);
      rollStack->push(adviseeID);
      rollStack->push(12);
    }
    else if(userChoice == 13){
      int userIn;
      int i = 0;
      while(i <5 && userIn != 0){
        rollBack();
        cout << "If you want to continue to roll back, enter 1, if you would like to exit rollback, enter 0: " << endl;
        cin >> userIn;
      }
    }
    userChoice = displayMenu();

  }

  BST<Student>* tempStudent = new BST<Student>;
  tempStudent = goldStudent;

  BST<Faculty>* tempFaculty = new BST<Faculty>;
  tempFaculty = goldFaculty;

  goldStudent->fileProcessor("studentTable.txt");
  goldFaculty->fileProcessor("facultyTable.txt");
  }

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

  if(goldFaculty->containsCheck(facAdvisID)){
    advisee = goldFaculty->containsAdviseeList(facAdvisID);
    advisee->insertFront(id);
  }


  Student temp(name, id, level, gradYear, major, gPA, facAdvisID);
  deletedStudent = temp;
  goldStudent->insert(temp);
  rollStack->push(id);
}

// for rollback method
void Simulation::addStudent(string name, int id, string level, int gradYear, string major, double gpa, int facAdvisId){
  Student temp(name, id, level, gradYear, major, gpa, facAdvisId);
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
  cin >> tempAdvisee;
  while(tempAdvisee != 0){
    temp.addAdvisee(tempAdvisee);
    deletedFaculty = temp;
    cin >> tempAdvisee;
  }
  goldFaculty->insert(temp);
  rollStack->push(id);
}

// for rollback method
void Simulation::addFaculty(string name, int id, string level, string dept){
  Faculty temp(name, id, level, dept);
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
  //deleteAdvisee(id, )
}

void Simulation::deleteFaculty(int id){
  advisee = goldFaculty->containsAdviseeList(id);
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
    cout << advisee->peek(i) << endl;
    goldStudent->contains(id);
  }
}

int Simulation::changeStudentAdvisor(int studentID, int facultyID){
  if(goldFaculty->containsCheck(facultyID)){
    advisee = goldFaculty->containsAdviseeList(facultyID);
    advisee->insertFront(studentID);
    return goldStudent->containsChange(studentID, facultyID);
  }
  else{
    cout << "This advisor is not in the database, please try again" << endl;
  }

}


int Simulation::deleteAdvisee(int studentID, int facultyID){
  advisee = goldFaculty->containsAdviseeList(facultyID);
  for (int i=0; i<advisee->size(); ++i){
    if (advisee->peek(i) == studentID){
      advisee->removeFrom(i);
    }
  }
  return studentID;
}

void Simulation::readFiles(){
    ifstream inFS; // student buffer
    ifstream inFS2; // faculty buffer
    string fileLine; // for student
    string fileLine2; // for faculty 
      inFS.open("studentTable.txt");
      cout << "Student file opened" << endl;
      getline(inFS, fileLine);
      while(!inFS.fail()){
        cout << "file line: " << fileLine << endl;
        string name = fileLine;
        cout << "name " << name << endl;
        getline(inFS, fileLine);
        int id = stoi(fileLine);
        getline(inFS, fileLine);
        string level = fileLine;
        getline(inFS, fileLine);
        int gradYear = stoi(fileLine);
        getline(inFS, fileLine);
        double gpa = stod(fileLine);
        getline(inFS, fileLine);
        string major = fileLine;
        getline(inFS, fileLine);
        int facID = stoi(fileLine);
        Student temp(name, id, level, gradYear, major, gpa, facID);
        temp.printInfo();
        goldStudent->insert(temp);
        getline(inFS, fileLine);
      }
      inFS.close();
      inFS2.open("facultyTable.txt");
      cout << "fac file opened" << endl;
      getline(inFS2, fileLine2);
      while(!inFS2.fail()){
        cout << "file line2: " << fileLine2 << endl;
        string name = fileLine2;
        cout << "name: " << name << endl;
        getline(inFS2, fileLine2);
        int id = stoi(fileLine2);
        getline(inFS2, fileLine2);
        string level = fileLine2;
        getline(inFS2, fileLine2);
        string department = fileLine2;
        Faculty temp(name, id, level, department);
        getline(inFS2, fileLine2);
        int numAdvisees = stoi(fileLine2);
        for(int i = 0; i < numAdvisees;++i){
          getline(inFS2, fileLine2);
          temp.addAdvisee(stoi(fileLine2));
        }
        goldFaculty->insert(temp);
        getline(inFS2, fileLine2);
      }
      inFS2.close();

}

void Simulation::rollBack(){
  if (rollStack->peek() == 7){ // tells us which action to undo - undoing the added student
    rollStack->pop(); // pop the indicator
    int id = rollStack->pop();
    deleteStudent(id);
  }

  else if (rollStack->peek() == 8){ // undoing the deleted student
    rollStack->pop();
    // use stored class member to access values and add student
    addStudent(deletedStudent.getName(), deletedStudent.getID(), deletedStudent.getLevel(), deletedStudent.getGradYear(), deletedStudent.getMajor(), deletedStudent.getGpa(), deletedStudent.getFacAdvisiD());
  }
  else if (rollStack->peek() == 9){ // undoing the added faculty member
    rollStack->pop();
    int id = rollStack->pop(); 
    deleteFaculty(id);
  }
  else if (rollStack->peek() == 10){ // undoing the deleted faculty member
    rollStack->pop();
    // use stored class member to access values and re-add faculty member 
    addFaculty(deletedFaculty.getName(), deletedFaculty.getID(), deletedFaculty.getLevel(), deletedFaculty.getDepartment());
  }
  else if(rollStack->peek() == 11){ // un do the changed advisor
    rollStack->pop();
    int prevID = rollStack->pop();
    int stuID = rollStack->pop();
    changeStudentAdvisor(stuID, prevID);

  }
  else if(rollStack->peek() == 12){ // re-add removed advisee
    rollStack->pop();
    int adviseeId = rollStack->pop();
    int facId = rollStack->pop();
    advisee = goldFaculty->containsAdviseeList(facId);
    advisee->insertFront(adviseeId);
  }
  return;
}
