#include <iostream>
#include "FileHandler.hpp"
#include "test.hpp"

int main(int argc, char *argv[])
{

  FileHandler fileHandler;

  if(fileHandler.openFile("/home/khaled/Cpp/Projects/808s_Text_Editor/hello.txt"))
  {
    Test test;
    test.testloop(&fileHandler);
  }
  else{
    std::cout << "Error Opening File" << std::endl;
  }
  fileHandler.file.close();

  return 0;
}
