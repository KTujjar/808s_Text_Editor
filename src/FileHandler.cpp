#include "logic.hpp"


bool logic::FileHandler::openFile(std::string filePath)
{
  file.open(filePath, std::ios::in | std::ios::out);
  return file.is_open();
}

std::string logic::FileHandler::getFileContents()
{
  buffer << file.rdbuf();
  std::string fileContents = buffer.str();
  return fileContents;
}
