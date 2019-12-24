//
// Created by shaked on 18/12/2019.
//

#ifndef EX3_PRINT_H
#define EX3_PRINT_H
#include "Command.h"
#include "Singleton.h"
#include <iostream>

using namespace std;
class Print : public Command {
string string_to_print;
public:
  // need to delete execute.
    virtual int execute(vector<string> tokens, int curr_index);
};


#endif //EX3_PRINT_H
