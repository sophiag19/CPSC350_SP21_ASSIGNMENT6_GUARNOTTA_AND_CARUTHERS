  
/* Sarah Caruthers and Sophia Guarnotta
2350081, 
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#ifndef DLSTACK4_H
#define DLSTACK4_H
#include "DLList.h"

template <typename T> //allows for generic type placeholder
// implementation must go in header file
// templates similar to generics in java

class DlStack{
public:
  DlStack();
  ~DlStack();

  void push(T c); //add to top
  T pop(); //remove from top
  T peek(); //return top item without removing
  DLList<T> getStackDL();
  bool isEmpty();
  int size();

private:
  DLList<T> stackDL;
};

template <typename T>
DlStack<T>::DlStack(){

}

template <typename T>
DlStack<T>::~DlStack(){

}

template <typename T>
int DlStack<T>::size(){
  return (stackDL.size());
}

template <typename T>
bool DlStack<T>::isEmpty(){
  return (stackDL.isEmpty());
}

template <typename T>
void DlStack<T>::push(T data){
  stackDL.insertFront(data);
}

template <typename T>
T DlStack<T>::pop(){
  return (stackDL.removeFront());
}

template <typename T>
T DlStack<T>::peek(){
  return (stackDL.peek(0));
}

template <typename T>
DLList<T> DlStack<T>::getStackDL(){
  return stackDL;
}


#endif
