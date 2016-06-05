#include <iostream>
#include <fstream>
#include "brainfuck.h"
void usage()
{
  std::cout << "./interpreter" << std::endl;
  std::cout << "./interpreter <program.txt> <input.txt>" << std::endl;
}

int main(int argc, char* argv[]){
  Brainfuck bf;
  if(argc == 1)
    {
      bf.run();
    }
  else if(argc == 3)
    {
      bool run = true;
      std::ifstream file;
      // Get program text
      file.open(argv[1]);
      if(file.is_open())
	{
	  file >> bf.program;
	}
      else
	{
	  run = false;
	}
      file.close();

      // Get input text
      file.open(argv[2]);
      if(file.is_open())
	{
	  file >> bf.input;
	}
      else
	{
	  run = false;
	}
      file.close();
      
      if(run)
	bf.run(false);
    }
  else
    {
      usage();
    }
  return 0;
}
