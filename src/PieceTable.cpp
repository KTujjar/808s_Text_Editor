#include "PieceTable.hpp"

PieceTable::PieceTable(std::string orig){
  original = orig;
  insertPiece(0, original.size(), Piece::BufferType::ORIGINAL);
}

void PieceTable::handleInsert(int idx, std::string text)
{
  std::vector<Piece> temp = pieces;

  pieces.clear();

  add = text;

  Piece addPiece;
  addPiece.start = idx;
  addPiece.length = text.length();
  addPiece.source = Piece::BufferType::ADD;

  bool pieceAdded = false;

  for(Piece i : temp)
  {
    if(i.start + i.length < idx && pieceAdded == false){
      insertPiece(i.start, i.length, i.source);
    }
    else if(i.start > idx){
      insertPiece(addPiece.start, addPiece.length, addPiece.source);
      insertPiece(i.start, i.length, i.source);
      pieceAdded = true;
    }
    else if(i.start + i.length > idx && pieceAdded == false){

      insertPiece(i.start,idx - i.start, Piece::BufferType::ORIGINAL);
      insertPiece(addPiece.start, addPiece.length, addPiece.source);
      insertPiece((addPiece.start + addPiece.length), ((i.start + i.length + addPiece.length) -
                  (addPiece.start + addPiece.length)), Piece::BufferType::ORIGINAL);
    }
  }
}

void PieceTable::printPieces()
{
  for(Piece i : pieces)
  {
    std::cout << "start: " << i.start << " length: " << i.length;
    if(i.source == Piece::BufferType::ORIGINAL){
      std::cout << " source: " << "original" << std::endl;
    }
    else{
      std::cout << " source: " << "add" << std::endl;
    }
  }
  std::cout << "\n" << std::endl;
}

void PieceTable::handleDelete(int start, int length)
{

}

void PieceTable::insertPiece(int idx, int length, Piece::BufferType src){
  Piece temp;
  temp.length = length;
  temp.source = src;
  temp.start = idx;
  pieces.emplace_back(temp);
}

void PieceTable::replacePiece(int beginIdx, int endIdx, std::string replacement){

}

void PieceTable::deletePiece(int beginIdx, int endIdx){

}
