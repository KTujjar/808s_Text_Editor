#include "GUI.hpp"

void GUI::Window::drawMain(int argc,char *argv[]){
  QApplication app(argc, argv);

  QMainWindow window;

  window.setWindowTitle("808s");
  window.resize(800,600);

  app.setStyleSheet("QMainWindow {background-color: rgba(0,0,0,100)}");

  window.show();
  app.exec();
}
