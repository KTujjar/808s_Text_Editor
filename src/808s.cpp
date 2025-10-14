#include <iostream>
#include "FileHandler.hpp"
#include "test.hpp"

int main(int argc, char *argv[])
{

  FileHandler fileHandler;


  if(fileHandler.openFile("/home/khaled/Cpp/Projects/808s/hello.txt"))
  {
    Test test;
    test.testloop(fileHandler.getFileContents());
  }
  else{
    std::cout << "Error OpeningFile" << std::endl;
  }

  return 0;
}
