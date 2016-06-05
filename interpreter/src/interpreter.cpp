#include <iostream>
#include "brainfuck.h"
void usage()
{
  std::cout << "./interpreter" << std::endl;
  std::cout << "./interpreter <program.txt> <input.txt>" << std::endl;
}

int main(int argc, char* argv[]){
  if(argc == 1)
    {
      Brainfuck bf;
      bf.run();
    }
  else
    {
      usage();
    }
  return 0;
}
