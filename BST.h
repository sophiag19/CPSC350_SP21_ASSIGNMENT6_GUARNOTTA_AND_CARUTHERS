/* Sarah Caruthers and Sophia Guarnotta
2350081, 2369941
caruthers@chapman.edu, guarnotta@chapman.edu
CPSC 350-03
Programming Assignment 6: Building a DataBase with Bianry Search Trees
*/ 

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include "DLList.h"
#include "Student.h" 
#include <string>
#include <fstream>
using namespace std;

template <typename T>
class TreeNode{
public:
  TreeNode(T d);
  ~TreeNode();
  TreeNode<T>* left;
  TreeNode<T>* right;
  T data;
};

template <typename T>
TreeNode<T>::TreeNode(T d){
  data = d;
  left = NULL;
  right = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode(){
  if (left != NULL){
    delete left;
  }
  if (right != NULL){
    delete right;
  }
}

template <typename T>
class BST{
public:
  BST();
  ~BST();
  int containsID(int d); // checks a node for a specified id, returns the id
  bool contains(int d);
  bool containsCheck(int d); // returns boolean if a tree contains a specified person
  void insert(T d);
  bool recContains(T d);
  DLList<int>* containsAdviseeList(int d); // returns the advisee list of a specified faculty member
  void printInOrder();
  void printPostOrder();
  void deleteValue(int d);
  void fileProcessor(string outFile);
  void fileProcessorHelper(TreeNode<T>* n, string outFile, ofstream& outFS);
  int containsChange(int studentID, int facultyID);
  T getMax();
  T getMin();
  T getMedian();
  private:
  TreeNode<T>* root;
  int size;
  bool recContainsHelper(TreeNode<T>* n, T d);
  void printIOHelper(TreeNode<T>* n);
  void printPOHelper(TreeNode<T>* n);
  void insertHelper(TreeNode<T>*& n, T& d);
  T getMaxHelper(TreeNode<T>* n);
  T getMinHelper(TreeNode<T>* n);
  TreeNode<T>* getSuccessor(TreeNode<T>* child);
  void findTarget(int key, TreeNode<T>*& target, TreeNode<T>*& parent);
};

template <typename T>
BST<T>::BST(){
  root = NULL;
  size = 0;
}

template <typename T>
BST<T>::~BST(){
  delete root;//recursively delete root
  size = 0;
}


template <typename T>
void BST<T>::printInOrder(){
  printIOHelper(root);
}
template <typename T>
void BST<T>::printIOHelper(TreeNode<T>* n){
  if(n!=NULL){
    printIOHelper(n->left);
    n->data.printInfo();
    printIOHelper(n->right);
  }
}


template <typename T>
void BST<T>::fileProcessor(string outFile){
  ofstream outFS;
  outFS.open(outFile);
  fileProcessorHelper(root, outFile, outFS);
  outFS.close();
}
template <typename T>
void BST<T>::fileProcessorHelper(TreeNode<T>* n, string outFile, ofstream& outFS){
  if(n!=NULL){
    fileProcessorHelper(n->left, outFile, outFS);
    outFS << n->data.toString();
    fileProcessorHelper(n->right, outFile, outFS);
  }
}

template <typename T>
void BST<T>::printPostOrder(){
  printPOHelper(root);
}
template <typename T>
void BST<T>::printPOHelper(TreeNode<T>* n){
  if(n!=NULL){
    printPOHelper(n->left);
    printPOHelper(n->right);
    cout << n->data << endl;
  }
}

template <typename T>
bool BST<T>::recContains(T d){
  return recContainsHelper(root,d);
}

template <typename T>
bool BST<T>::recContainsHelper(TreeNode<T>* n, T d){
  if(n==NULL){
    return false;
  }
  if(n->data==d){
    return true;
  }
  if(d > n->data){
    return recContainsHelper(n->right,d);
  } else{
    return recContainsHelper(n->left,d);
  }
}

template <typename T>
bool BST<T>::contains(int d){ //no repeated values
  if(root==NULL){
    return false;
  }
  if(root->data.getID()==d){
    root->data.printInfo();
    return true;
  }
  bool found = false;
  TreeNode<T>* current = root;
  while(!found){
    if(d > current->data.getID()){
      current = current->right;
    } else{
      current = current->left;
    }
    if(current==NULL){
      found = false;
      break;
    }
    if(current->data.getID()==d){
      current->data.printInfo();
      found = true;
      break;
    }
  }
  return found;
}

template <typename T>
bool BST<T>::containsCheck(int d){ //no repeated values
  if(root==NULL){
    return false;
  }
  if(root->data.getID()==d){
    root->data;
    return true;
  }
  bool found = false;
  TreeNode<T>* current = root;
  while(!found){
    if(d > current->data.getID()){
      current = current->right;
    } else{
      current = current->left;
    }
    if(current==NULL){
      found = false;
      break;
    }
    if(current->data.getID()==d){
      current->data;
      found = true;
      break;
    }
  }
  return found;
}

template <typename T>
DLList<int>* BST<T>::containsAdviseeList(int d){ //no repeated values
  DLList<int>* advisees;
  if(root==NULL){
    return advisees;
  }
  if(root->data.getID()==d){
    return root->data.getAdviseeList();
  }
  bool found = false;
  TreeNode<T>* current = root;
  while(!found){
    if(d > current->data.getID()){
      current = current->right;
    } else{
      current = current->left;
    }
    if(current==NULL){
      found = false;
      break;
    }
    if(current->data.getID()==d){
      advisees = current->data.getAdviseeList();
      found = true;
      break;
    }
  }
  return advisees;
}

template <typename T>
int BST<T>::containsID(int d){ //no repeated values
int stuID;
  if(root==NULL){
    return -1;
  }
  if(root->data.getID()==d){
    stuID = root->data.getFacAdvisiD();
    return stuID;
  }
  bool found = false;
  TreeNode<T>* current = root;
  while(!found){
    if(d > current->data.getID()){
      current = current->right;
    } else{
      current = current->left;
    }
    if(current==NULL){
      return -1;
      found = false;
      break;
    }
    if(current->data.getID()==d){
      stuID = current->data.getFacAdvisiD();
      found = true;
      break;
    }
  }
  return stuID;
}

template <typename T>
int BST<T>::containsChange(int studentID, int facultyID){ //no repeated values
  int prevID = 0;
  if(root==NULL){
    return prevID;
  }
  if(root->data.getID()==studentID){
    prevID = root->data.getFacAdvisiD();
    root->data.setFacAdvisID(facultyID);
    return prevID;
  }
  bool found = false;
  TreeNode<T>* current = root;
  while(!found){
    if(studentID > current->data.getID()){
      current = current->right;
    } else{
      current = current->left;
    }
    if(current==NULL){
      found = false;
      break;
    }
    if(current->data.getID()==studentID){
      prevID = current->data.getFacAdvisiD();
      current->data.setFacAdvisID(facultyID);
      found = true;
      break;
    }
  }
  return prevID;
}


template <typename T>
void BST<T>::insert(T d){
  insertHelper(root,d);
}

template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& n, T& d){
  if(n==NULL){
    n = new TreeNode<T>(d);
  } else if(d < n->data){
    insertHelper(n->left,d);
  } else{
    insertHelper(n->right,d);
  }

}

template <typename T>
T BST<T>::getMax(){
  if(root->data == NULL){
    cout << "Empty tree" << endl;
    return;
  }
  else{
    return getMaxHelper(root);
  }
}

template <typename T>
T BST<T>::getMaxHelper(TreeNode<T>* n){
  if(n->right == NULL){
    return n->data;
  } else{
    return getMaxHelper(n->right);
  }
}

template <typename T>
T BST<T>::getMin(){
  if(root->data == NULL){
    cout << "Empty tree" << endl;
    return;
  }
  else{
    return getMinHelper(root);
  }
}

template <typename T>
T BST<T>::getMinHelper(TreeNode<T>* n){
  if(n->left == NULL){
    return n->data;
  } else{
    return getMinHelper(n->left);
  }
}

template <typename T> //must be a balanced tree to work
T BST<T>::getMedian(){
  if(root->data == NULL){
    cout << "Empty tree" << endl;
    return;
  }
  else{
    return root->data;
  }
}
template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* child){
  while(child->left != NULL){
    child = child->left;
  }
  return child;
}
template <typename T>
void BST<T>::findTarget(int key, TreeNode<T>*& target, TreeNode<T>*& parent){
  while(target != NULL && target->data.getID() != key){
    parent = target;
    if(key < target->data.getID()){
      target = target->left;
    } else{
      target = target->right;
    }
  }
}

template <typename T>
void BST<T>::deleteValue(int d){
  TreeNode<T>* parent = NULL;
  TreeNode<T>* current = NULL;

  current = root;

  findTarget(d,current,parent);
  if(current==NULL){
    return;
  }
  //check if leaf
  if(current->left==NULL && current->right==NULL){
    //leaf is root
    if(current==root){
      root=NULL;
    }else { //not root
      if(current==parent->left){
        parent->left = NULL;
      } else{
        parent->right = NULL;
      }
    } //end case 1
    delete current;
  } else if (current->left!=NULL && current->right!=NULL){
    TreeNode<T>* suc = getSuccessor(current->right);
    T temp = suc->data;
    //cout << suc->data << endl;
    this->deleteValue(suc->data.getID());
    current->data = temp;

  } else{ //only 1 child
    TreeNode<T>* child;
    if(current->left!=NULL){
      child = current->left;
    } else{
      child = current->right;
    }
    if(current==root){
      root = child;
    } else{
      if(current==parent->left){
        parent->left = child;
      } else{
        parent->right = child;
      }
    }
    delete current; //free memory
  }

}


#endif
