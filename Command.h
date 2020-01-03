//
// Created by shaked on 18/12/2019.
//
/*
 * a virtual class, acting like an interface.
 * all kind of commands are inheriting him.
 */
#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include <string>
#include <vector>
using namespace std;

class Command {
 public:
  // execute the command
  virtual int execute(vector<string> &tokens, int curr_index) = 0;
};


#endif //EX3_COMMAND_H
