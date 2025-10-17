#include "test.hpp"
#include "PieceTable.hpp"

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

void Test::testloop(std::string orig)
{
  PieceTable pt(orig);
  while(true)
  {
    std::string input;
    std::cout<< "\ni: insert, d: delete\n"<< "insert <index> <text>\n" << "delete <start> <length>\n" << std::endl;
    std::getline(std::cin, input);
    std::vector<std::string> commands = handleInput(input);

    if(commands.size() < 3 || commands[0] == "" || commands[1] == "" || commands[2] == "")
    {
      std::cout << "Invalid Input" << std::endl;
      continue;
    }

    if(commands[0] == "i"){

      std::string text = commands[2];
      int position = std::stoi(commands[1]);

      pt.printPieces();
      pt.handleInsert(position, text);
      pt.printPieces();
    }
    else if(commands[0] == "h") {

      int start = std::stoi(commands[1]);
      int length = std::stoi(commands[2]);

      pt.handleDelete(start, length);
    }
    else{
      std::cout << "Invalid Input" << std::endl;
    }

  }
}
