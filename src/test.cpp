#include "test.hpp"

std::vector<std::string> handleInput(std::string input)
{
  std::istringstream iss(input);
  std::vector<std::string> result{std::istream_iterator<std::string>{iss}, {}};

  if(result.size() > 3)
  {
    std::cout << "Too many inputs" << std::endl;
    return {""};
  }

  return result;
}

void Test::testloop(FileHandler *file)
{
  std::string orig = file->getFileContents();
  PieceTable pt(orig);

  while(true)
  {
    std::string input;
    std::cout<< "\ni: insert, d: delete s: save\n"<< "insert <index> <text>\n" << "delete <start> <length>\n" << std::endl;
    std::getline(std::cin, input);
    std::vector<std::string> commands = handleInput(input);


    if(commands[0] == "i"){

      std::string text = commands[2];
      int position = std::stoi(commands[1]);

      std::cout << "\nBefore Insert:" << std::endl;
      pt.printPieces();
      pt.handleInsert(position, text);
      std::cout << "\nAfter Insert:" << std::endl;
      pt.printPieces();
    }
    else if(commands[0] == "d") {

      int start = std::stoi(commands[1]);
      int length = std::stoi(commands[2]);
      std::cout << "Before Delete:" << std::endl;
      pt.printPieces();
      pt.handleDelete(start, length);
      std::cout << "After Delete:" << std::endl;
      pt.printPieces();

    }
    else if(commands[0] == "s"){
      if(file->saveFile(&pt)){
        std::cout << "File Saved" << std::endl;
        break;
      }
      else{
        std::cout << "File could not be saved" << std::endl;
      }
    }
    else{
      std::cout << "Invalid Input" << std::endl;
    }

  }
}
