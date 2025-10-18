#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "PieceTable.hpp"

class FileHandler{
  public:

    std::fstream file;
    std::string path;

    bool saveFile(PieceTable *pt);
    bool openFile(std::string filePath);

    std::string getFileContents();
  private:
    std::ostringstream buffer;
};
