#ifndef DLSTACK4_H
#define DLSTACK4_H
#include "DLList2.h"

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


#endif
