#pragma once
#include <iostream>
#include <vector>
#include <string>


class PieceTable{
  public:
    PieceTable(std::string orig);

  private:
    //original buffer
    std::string original;

    //add buffer
    std::string add;

    //piece Descriptor struct
    struct Piece{

      //tells us which buffer to read from
      enum class BufferType {ORIGINAL, ADD};
      BufferType source;

      //index in that buffer to start reading from
      int start;

      //tells us how many characters to read from that buffer
      int length;
    };

    std::vector<Piece> pieces;

    void insertPiece(int idx, std::string text, Piece::BufferType src);
    void deletePiece(int beginIdx, int endIdx);
    void replacePiece(int beginIdx, int endIdx, std::string replacement);
};
