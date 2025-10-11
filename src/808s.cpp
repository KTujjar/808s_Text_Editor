#include <iostream>
#include "GUI.hpp"
#include "logic.hpp"

int main(int argc, char *argv[])
{
  GUI::Window view;

  view.drawMain(argc,argv);

  return 0;
}
