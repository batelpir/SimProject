//
// Created by shaked on 18/12/2019.
//

#ifndef EX3_PRINT_H
#define EX3_PRINT_H
#include "Command.h"
#include <iostream>

using namespace std;
class Print : public Command {
  vector<string> tokens;

public:
    Print(vector<string> tokens_input);
  // need to delete execute.
    virtual int execute(int curr_index);
};


#endif //EX3_PRINT_H
