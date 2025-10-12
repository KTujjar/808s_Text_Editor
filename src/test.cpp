#include "test.hpp"
#include "PieceTable.hpp"
void Test::testloop()
{
  PieceTable pt;
  while(true)
  {
    std::string input;
    std::cin >> input;

    if(input[0] == 'i')
    {

    }
    else if(input[0] == 'd')
    {

    }
    else{
      std::cout << "incorrect operation" << std::endl;
    }
  }
}
