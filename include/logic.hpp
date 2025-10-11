#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace logic{

class PieceTable{
  public:

    void insertText(int idx, std::string text);
    void deleteText(int beginIdx, int endIdx);
    void replaceText(int beginIdx, int endIdx, std::string replacement);

  private:

    //original buffer
    std::string original;

    //add buffer
    std::string add;

    //piece Descriptor struct
    struct pieceDescriptor{

      //tells us which buffer to read from
      std::string source;

      //index in that buffer to start reading from
      int start;

      //tells us how many characters to read from that buffer
      int length;
    };

    std::vector<pieceDescriptor> pieces;

};

class FileHandler{
  public:

    std::fstream file;

    bool openFile(std::string filePath);

  std::string getFileContents();
  private:
    std::ostringstream buffer;

};

}
