#include <iostream>
#include "FileHandler.hpp"
#include <QApplication>
#include "test.hpp"
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{


  QApplication app(argc, argv);
  MainWindow win;
  win.show();
  return app.exec();

  // FileHandler fileHandler;
  //
  // if(fileHandler.openFile("/home/khaled/Cpp/Projects/808s_Text_Editor/hello.txt"))
  // {
  //   Test test;
  //   test.testloop(&fileHandler);
  // }
  // else{
  //   std::cout << "Error Opening File" << std::endl;
  // }
  // fileHandler.file.close();
}
