#include <iostream>
#include "GUI.hpp"
#include "FileHandler.hpp"
#include "PieceTable.hpp"
#include "test.hpp"

int main(int argc, char *argv[])
{

  FileHandler fileHandler;


  if(fileHandler.openFile("/home/khaled/Cpp/Projects/808s/hello.txt"))
  {
    PieceTable pt(fileHandler.getFileContents());
    Test test;
    test.testloop();
  }
  else{
    std::cout << "Error OpeningFile" << std::endl;
  }

  return 0;
}
