#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileProcessor{
public:
  FileProcessor();
  ~FileProcessor();
  void writeToFile(string inFile, string outFile, string input);
  void readFromFile(string inFile);
}
;

#endif
