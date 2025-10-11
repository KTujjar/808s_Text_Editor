#pragma once
#include <iostream>
#include <string>

namespace logic{

  class PieceTable{
  public:

    void insertText(int idx, std::string text);
    void deleteText(int beginIdx, int endIdx);
    void replaceText(int beginIdx, int endIdx, std::string replacement);

  private:

  };

}
