//
// Created by shaked on 18/12/2019.
//

#ifndef EX3_PRINT_H
#define EX3_PRINT_H
#include "Command.h"
#include "Singleton.h"
#include <iostream>
/*
 * the command which prints data to the screen.
 * the data is given from tokens vector.
 * is inherit Command because it is kind of command.
 * is called in parser.
 */
using namespace std;
class Print : public Command {
public:
    virtual int execute(vector<string> &tokens, int curr_index);
};


#endif //EX3_PRINT_H
