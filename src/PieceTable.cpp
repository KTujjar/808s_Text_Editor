#include "PieceTable.hpp"

PieceTable::PieceTable(std::string orig){
  original = orig;
  insertPiece(0, original.size(), Piece::BufferType::ORIGINAL);
}

void PieceTable::handleInsert(int idx, std::string text)
{
  std::vector<Piece> temp = pieces;

  pieces.clear();

  add.append(text);

  Piece addPiece;
  addPiece.start = add.size() - text.size();
  addPiece.length = text.length();
  addPiece.source = Piece::BufferType::ADD;

  bool pieceAdded = false;
  int docIdx = 0;

  //add idx variable to track
  for(Piece i : temp)
  {
    if(pieceAdded || i.source == Piece::BufferType::ADD){
      insertPiece(i.start, i.length, i.source);
    }
    else if(!pieceAdded && docIdx + i.length < idx){
      insertPiece(i.start, i.length, i.source);
    }
    else if(!pieceAdded && docIdx >= idx){
      insertPiece(addPiece.start, addPiece.length, addPiece.source);
      insertPiece(i.start, i.length, i.source);
      pieceAdded = true;
    }
    else if(!pieceAdded && docIdx + i.length > idx){
      insertPiece(i.start, idx-i.start, i.source);
      insertPiece(addPiece.start, addPiece.length, addPiece.source);
      insertPiece(idx-i.start, i.length - (idx - i.start), i.source);
      pieceAdded = true;
    }
    docIdx += i.length;
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
