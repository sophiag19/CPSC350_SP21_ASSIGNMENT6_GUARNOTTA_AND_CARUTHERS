#include "FileProcessor.h"

using namespace std;

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}

void FileProcessor::writeToFile(string inFile, string outFile, string input){

}

void FileProcessor::readFromFile(string inFile){
  ifstream inFS;
  inFS.open(inFile + "Table.txt");
  string content;
  while (!inFS.eof()){
    getline(inFS, content);
  }
  inFS.close();
  //return content;
}
