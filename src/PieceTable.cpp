#include "PieceTable.hpp"

PieceTable::PieceTable(std::string orig){
  original = orig;
  insertPiece(0, original, Piece::BufferType::ORIGINAL);
}

void PieceTable::insertPiece(int idx, std::string text, Piece::BufferType src){
  Piece temp;
  temp.length = text.size();
  temp.source = src;
  temp.start = idx;
  pieces.emplace_back(temp);
}

void PieceTable::replacePiece(int beginIdx, int endIdx, std::string replacement){

}

void PieceTable::deletePiece(int beginIdx, int endIdx){

}
