#ifndef _BRAINFUCK_H
#define _BRAINFUCK_H

#include <string>
#include <iostream>
#include <vector>

class Brainfuck{
 private:
  std::vector<int> *data;
  int data_head;
  
  // input string info
  int input_head;

  // program string info
  int program_head;

  void reset_heads();
 
  // The Brainfuck commands
  void left_angle();
  void right_angle();
  void plus();
  void minus();
  void dot();
  void comma();
  void left_square();
  void right_square();
  void run_command();

 public:
  Brainfuck();
  ~Brainfuck();
  void run(bool);
  void run();
  void getInput();
  void getProgram();

  std::string program;
  std::string input;
};

#endif //_BRAINFUCK_H
