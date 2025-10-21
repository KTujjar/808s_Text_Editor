#include "PieceTable.hpp"

PieceTable::PieceTable(std::string orig){
  original = orig;
  documentLength += orig.length();
  insertPiece(0, original.size(), Piece::BufferType::ORIGINAL);
}

void PieceTable::handleInsert(int idx, std::string text){
  std::vector<Piece> temp = pieces;

  //might be a better way where i create temp and loop through pieces. adding to temp then make pieces temp.
  pieces.clear();

  add.append(text);

  Piece addPiece;
  addPiece.start = add.size() - text.size();
  addPiece.length = text.length();
  addPiece.source = Piece::BufferType::ADD;

  bool pieceAdded = false;
  int docIdx = 0;

  idx = std::clamp(idx, 0, documentLength - 1);

  for(Piece i : temp){
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
  documentLength += text.length();
}

void PieceTable::handleDelete(int start, int length){
  std::vector<Piece> temp;

  int docIdx = 0;

  int leftPos = start;
  int rightPos = start + length;

  for(Piece i : pieces){
    if(docIdx <= rightPos && docIdx + i.length > leftPos){ //checks overlap
      if(docIdx == leftPos && docIdx + i.length == rightPos){
        std::cout << "0" << std::endl;
        continue;
      }
      else if(docIdx < leftPos && docIdx + i.length > rightPos){
        std::cout << "1" << std::endl;
        Piece newPiece;
        //left piece
        newPiece.start = i.start;
        newPiece.length = leftPos - docIdx;
        newPiece.source = i.source;
        temp.emplace_back(newPiece);

        //right piece
        newPiece.start = rightPos - docIdx;
        newPiece.length = (docIdx + i.length) - rightPos;
        newPiece.source = i.source;
        temp.emplace_back(newPiece);
      }
      else if(docIdx < leftPos && docIdx + i.length < rightPos){
        std::cout << "2" << std::endl;
        Piece newPiece;
        //left piece
        newPiece.start = i.start;
        newPiece.length = leftPos - docIdx;
        newPiece.source = i.source;
        temp.emplace_back(newPiece);
        // leftPos += (i.length - newPiece.length);
      }
      else if(docIdx >= leftPos && docIdx + i.length <= rightPos){
        std::cout << "3" << std::endl;

        continue;
      }
      else if(docIdx >= leftPos && docIdx + i.length > rightPos){
        std::cout << "4" << std::endl;
        Piece newPiece;
        newPiece.start = rightPos - docIdx;
        newPiece.length = (docIdx + i.length) - rightPos;
        newPiece.source = i.source;
        temp.emplace_back(newPiece);
      }
    }
    else{
      std::cout << "5" << std::endl;
      temp.emplace_back(i);
    }

    docIdx += i.length;
  }

  pieces = temp;
}

void PieceTable::insertPiece(int idx, int length, Piece::BufferType src){
  Piece temp;
  temp.length = length;
  temp.source = src;
  temp.start = idx;
  pieces.emplace_back(temp);
}

void PieceTable::printPieces(){
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

void PieceTable::handleSave(std::ofstream *file){
  for(Piece i : pieces){
    if(i.source == Piece::BufferType::ORIGINAL){
      *file << original.substr(i.start, i.length);
    }
    else {
      *file << add.substr(i.start, i.length);
    }
  }
}

std::string PieceTable::getFullText(){
  std::string text = "";
  for(Piece i : pieces){
    if(i.source == Piece::BufferType::ORIGINAL){
      text += original.substr(i.start, i.length);
    }
    else {
      text += add.substr(i.start, i.length);
    }
  }
  return text;
}
