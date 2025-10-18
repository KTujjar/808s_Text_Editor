#include "FileHandler.hpp"

bool FileHandler::openFile(std::string filePath)
{
  path = filePath;
  file.open(filePath, std::ios::in | std::ios::out);
  return file.is_open();
}

std::string FileHandler::getFileContents()
{
  buffer << file.rdbuf();
  std::string fileContents = buffer.str();
  return fileContents;
}

bool FileHandler::saveFile(PieceTable *pt){
  std::ofstream outputFile(path, std::ios::trunc);
  if(outputFile.is_open()) {
    pt->handleSave(&outputFile);
    outputFile.close();
    return true;
  }
  return false;
}
