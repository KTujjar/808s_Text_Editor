#include <iostream>
#include "GUI.hpp"
#include "logic.hpp"

int main(int argc, char *argv[])
{

  logic::FileHandler fileHandler;
  if(fileHandler.openFile("/home/khaled/Cpp/Projects/808s/hello.txt"))
  {
    GUI::Window view;
    view.drawMain(argc,argv,fileHandler.getFileContents());
  }
  else{
    std::cout << "Error OpeningFile" << std::endl;
  }

  return 0;
}
