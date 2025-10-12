#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class FileHandler{
  public:

    std::fstream file;

    bool openFile(std::string filePath);

    std::string getFileContents();
  private:
    std::ostringstream buffer;
};
