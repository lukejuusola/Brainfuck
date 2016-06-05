#include "brainfuck.h"
#include <vector>

Brainfuck::Brainfuck()
{
  this->data = new std::vector<int>;
  for(int i = 0; i < 500; i++)
    this->data->push_back(0);
  this->program = "";
  this->input = "";
  this->data_head = 250;
  this->input_head = 0;
  this->program_head = 0;
}

Brainfuck::~Brainfuck()
{
  delete this->data;
}

void Brainfuck::left_angle()
{
  this->data_head--;
  this->program_head++;
}

void Brainfuck::right_angle()
{
  this->data_head++;
  this->program_head++;
}

void Brainfuck::plus()
{ 
  (*this->data)[this->data_head]++;
  this->program_head++;
}

void Brainfuck::minus()
{
  (*this->data)[this->data_head]--;
  this->program_head++;
}

void Brainfuck::dot()
{
  std::cout << (char) (*this->data)[this->data_head];
  this->program_head++;
}

void Brainfuck::comma()
{
  (*this->data)[this->data_head] = (int) this->input[this->input_head];
  this->input_head++;
  this->program_head++;
}

void Brainfuck::left_square()
{
  this->program_head++;
  unsigned short int lefts = 1; // Progressive count of unclosed [
  if((*this->data)[this->data_head] == 0)
    {
      while(lefts != 0)
	{
	  if(this->program[this->program_head] == '[')
	    lefts++;
	  else if(this->program[this->program_head] == ']')
	    lefts--;
	  this->program_head++;
	}
    }
}

void Brainfuck::right_square(){
  this->program_head--;
  unsigned short int rights = 1; // Progressive count of unclosed ]
  if((*this->data)[this->data_head] != 0)
    {
      while(rights != 0)
	{
	  if(this->program[this->program_head] == ']')
	    rights++;
	  else if(this->program[this->program_head] == '[')
	    rights--;
	  this->program_head--;
	}
    }
  else
    {
      this->program_head += 2;
    }
}

void Brainfuck::run_command()
{
  char command = (char) this->program[this->program_head];
  switch(command)
    {
      case '<':
	this->left_angle();
	break;
      case '>':
        this->right_angle();
        break;
      case '+':
        this->plus();
        break;
      case '-':
        this->minus();
        break;
      case '.':
        this->dot();
        break;
      case ',':
        this->comma();
        break;
      case '[':
        this->left_square();
        break;
      case ']':
        this->right_square();
        break;
	//default:
        //throw ProgramInputException();
    }

}

void Brainfuck::run()
{
  this->run(true);
}
void Brainfuck::run(bool prompt)
{
  std::cout << "Welcome to the Brainfuck Interpreter";
  while(true)
    {
      this->reset_heads();
      std::cout << std::endl;
      if(prompt)
	{
	  this->getProgram();
	  this->getInput();
	}
      try
	{
	  while((unsigned int) this->program_head < this->program.length())
	    this->run_command();
	  std::cout << std::endl;
	}
      catch(...)
	{
	  std::cout << "An error occurred with the program" << std::endl;
	}
    }
  std::cout << std::endl << std::endl << "Program terminated" << std::endl;
}
void Brainfuck::getProgram()
{
  std::cout << "program >>> ";
  std::cin >> this->program;
}

void Brainfuck::getInput()
{
  std::cout << "input   >>> ";
  std::cin.ignore();
  std::getline(std::cin, this->input);
}

void Brainfuck::reset_heads()
{
  this->program_head = 0;
  this->input_head = 0;
}
