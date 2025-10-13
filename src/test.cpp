#include "test.hpp"
#include "PieceTable.hpp"

std::vector<std::string> handleInput(std::string input)
{
  std::vector<std::string> result = {"","",""};
    int resultIdx = 0;
    for(char c : input){
      if(resultIdx == result.size())
      {
        std::cout << "too many inputs" << std::endl;
        return {""};
        break;
      }
      if(c != ' '){
        result[resultIdx] += c;
      }
      else{
        resultIdx++;
      }
    }
  return result;
}

void Test::testloop(std::string orig)
{
  PieceTable pt(orig);
  while(true)
  {
    std::string input;
    std::cout<< "\ni: insert, d: delete\n"<< "insert <position> <text>\n" << "delete <start> <length>\n" << std::endl;
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

      pt.handleInsert(position, text);
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
