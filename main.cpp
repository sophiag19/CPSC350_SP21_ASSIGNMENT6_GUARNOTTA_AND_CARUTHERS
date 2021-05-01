#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

int main(){
  BST<int> test;
  test.insert(1);
  test.insert(2);
  test.insert(3);
  //test.printInOrder();
  test.deleteValue(2);
  test.printInOrder();
  return 0;
}
