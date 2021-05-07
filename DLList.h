/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#ifndef DL_LIST_H
#define DL_LIST_H
#include <iostream>

using namespace std;

#include <cstdlib>

/*
 * Class ListNode contains variables for a node in a doubly linked list, data, and pointers to the next and previous node
 */
template <typename T>
class ListNode{
public:
  ListNode(T d);
  ~ListNode();
  T data;
  ListNode<T>* next;
  ListNode<T>* prev;
};

//default constructor
template <typename T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

//default destructor
template <typename T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}

/*
 * Class DLList
 * uses ListNode to implement a doubly linked list
 * contains methods and variables for a doubly linked list
 */
template <typename T>
class DLList{
public:
  DLList();
  ~DLList();
  int size();
  bool isEmpty();
  void insertFront(T d);
  void insertBack(T d);
  void insertAt(int p, T d);
  T removeFront();
  T removeBack();
  T removeFrom(int p);
  T peek(int p);

private:
  ListNode<T>* front;
  ListNode<T>* back;
  int m_size;
};

//default constructor - sets variables to arbitrary values
template <typename T>
DLList<T>::DLList(){
  front = NULL;
  back = NULL;
  m_size = 0;
}

//default destructor - removes all elements from the list
template <typename T>
DLList<T>::~DLList(){
  while(!isEmpty()){
    removeBack();
  }
  front = NULL;
  back = NULL;
}

//method isEmpty - returns true if the size of the list is zero
template <typename T>
bool DLList<T>::isEmpty(){
  return (m_size==0);
}

//method size - returns an int of the size of the list
template <typename T>
int DLList<T>::size(){
  return m_size;
}

/*
 * method insertFront
 * takes in data as a parameter and adds that data to a new node at the front of the list
 */
template <typename T>
void DLList<T>::insertFront(T d){
  ListNode<T>* newNode = new ListNode<T>(d);

  if(isEmpty()){
    back = newNode;
  } else{
    front->prev = newNode;
  }
  newNode->next = front;
  front = newNode;
  ++m_size;
}

/*
 * method insertBack
 * takes in data as a parameter and adds that data to a new node at the back of the list
 */
template <typename T>
void DLList<T>::insertBack(T d){
  ListNode<T>* newNode = new ListNode<T>(d);
  if(isEmpty()){
    front = newNode;
  } else{
    back->next = newNode;
    newNode->prev = back;
  }
  back = newNode;
  ++m_size;
}

/*
 * method insertAt
 * takes in data and position as parameters and adds that data to a new node at the specified position in the list
 */
template <typename T>
void DLList<T>::insertAt(int p, T d){
  //checks for valid position and handles exception by message to screen
  try {
    if(p < 0 || p >= m_size){
      if(isEmpty()){
        insertFront(d);
        return;
      }
      if(p>=m_size-1){
        insertBack(d);
        return;
      }
      ListNode<T>* newNode = new ListNode<T>(d);
      int currIdx = 0;
      ListNode<T>* currNode = front;
      while(currIdx < p){
        ++currIdx;
        currNode = currNode->next;
      }
      newNode->next = currNode->next;
      currNode->next->prev = newNode;
      newNode->prev = currNode;
      currNode->next = newNode;
        ++m_size;
    }
    else{
      throw -1;
    }

  }
  catch(int i){
    if(i == -1){
      cout << "Sorry, that is not a valid position in the list" << endl;
    }
  }
}
/*
 * method removeFront
 * removes the node at the front of the list by setting the second node's  previous pointer to null
 * returns the data of the node being removed
 */
template <typename T>
T DLList<T>::removeFront(){
  //checks if list is empty and handles with message to screen
  T ret;
  try{
    if(!isEmpty()){
      ret = front->data;
      if(front->next == NULL){
        back = NULL;
      } else{
        front->next->prev = NULL;
      }
      front=front->next;
      --m_size;
    }
  }
  catch(int i){
    if(i == -1){
      cout << "An exception occurred, you tried to remove the front of an empty list " << endl;
    }
  }
  //free(ret);
  return ret;
}
/*
 * method removeBack
 * removes the node at the back of the list by setting the penultimate node's next pointer to null
 * returns the data of the node being removed
 */
template <typename T>
T DLList<T>::removeBack(){
  //checks if list is empty and handles with message to screen
  T ret;
  try {
    if(!isEmpty()){
      ret = back->data;
      if(front->next==NULL){
        front = NULL;
      } else{
        back->prev->next = NULL;
      }
      back = back->prev;
      --m_size;
    }
    else{
      throw -1;
    }
  }
  catch (int i){
    if(i == -1){
      cout << "An exception occurred, you tried to remove the back of an empty list" << endl;
    }
  }
  //free(ret);
  return ret;
}

/*
 * method removeFrom
 * takes an integer parameter p for the position of the node to be removed
 * sets the pointers that were pointing to the node at p to the nodes before and after the node at p
 * returns the data of the node being removed
 */
template <typename T>
T DLList<T>::removeFrom(int p){
  //checks if empty and handles with message to screen
    T ret;
  try {
    if(!isEmpty()){
      if(p>=m_size-1){
        return removeBack();
      }
      --m_size;
      int currIdx = 0;
      ListNode<T>* currNode = front;
      while(currIdx < p){
        ++currIdx;
        currNode = currNode->next;
      }
      ret = currNode->next->data;
      currNode->next->prev = NULL;
      currNode->next->next->prev = currNode;
      currNode->next = currNode->next->next;
    }
    else{
      throw -1;
    }
  }
  catch(int i){
    if(i == -1){
      cout << "An exception occurred, you tried to remove from an empty list" << endl;
    }
  }
  //free(ret);
  return ret;
}
/*
 * method peek
 * takes an integer parameter p for the position of the node to be looked at
 * returns the data from the node at p
 */
template <typename T>
T DLList<T>::peek(int p){
  //checks if empty and handles with message to screen
  T ret;
  try {
    if(!isEmpty()){
      if(p<=0){
        return front->data;
      }
      int currIdx = 0;
      ListNode<T>* currNode = front;
      while(currIdx < p){
        ++currIdx;
        currNode = currNode->next;
      }
      ret = currNode->data;
    }
    else{
      throw -1;
    }
  }
  catch(int i){
    if(i == -1){
      cout << "An exception has occurred, you tried to peek at an empty list" << endl;
    }
    cout << "ret " << ret<< endl;
  }
  return ret;
}

#endif
