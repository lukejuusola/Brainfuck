#ifndef _BRAINFUCK_H
#define _BRAINFUCK_H

#include <string>
#include <iostream>
#include <vector>

class Brainfuck{
 private:
  std::vector<int> *data;
  int data_head;
  
  std::string input;
  int input_head;
  int input_length;

  std::string program;
  int program_head;
  int program_length;

  void reset_heads();
 
  // The Brainfuck commandsx
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
};

#endif //_BRAINFUCK_H
