#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"
#include "Simulation.h"

using namespace std;

int main(){
  /*BST<Faculty> test;
  Faculty f("Sarah", 1, "Soph", "crean");
  test.insert(f);
  f.addAdvisee(12);
  f.addAdvisee(13);
  f.addAdvisee(14);
  Faculty f2("Sophia", 5, "Freshman", "fowler");
  test.insert(f2);
  f2.addAdvisee(15);
  f2.addAdvisee(16);
  Faculty f3("So", 3, "Fres", "fowl");
  test.insert(f3);
  f3.addAdvisee(17);
  f3.addAdvisee(18);
  test.printInOrder();
  */
  Simulation s1;
  s1.simulate();
  return 0;
}
