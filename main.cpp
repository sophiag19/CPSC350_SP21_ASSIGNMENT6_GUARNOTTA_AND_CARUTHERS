#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

int main(){
  BST<Faculty> test;
  Faculty f("Sarah", 1, "Soph", "crean");
  test.insert(f);
  f.addAdvisee(12);
  f.addAdvisee(13);
  f.addAdvisee(14);
  Faculty f2("Sophia", 2, "Freshman", "fowler");
  test.insert(f2);
  f2.addAdvisee(15);
  f2.addAdvisee(16);
  test.printInOrder();
  return 0;
}
