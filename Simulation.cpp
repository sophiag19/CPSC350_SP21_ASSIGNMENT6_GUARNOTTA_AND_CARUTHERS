#include "Simulation.h"
#include <iostream>
using namespace std;

Simulation::Simulation(){

}

Simulation::~Simulation(){

}

int Simualtion::displayMenu(){
  int choice;
  cout << "Please enter 1 to print out all the students and their information in ascending order of iD number." << endl;
  cout << "Please enter 2 to print out all the faculty members and their information in ascending order of iD number." << endl;"
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
  cout << "Please enter 14 to exit."
}
