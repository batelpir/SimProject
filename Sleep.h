//
// Created by shaked on 18/12/2019.
//

#ifndef EX3_SLEEP_H
#define EX3_SLEEP_H

#include <sstream>
#include <unistd.h> // for sleep
#include "Command.h"
/*
 * the command which make the running of thr program to sleep for a while.
 * is inherit Command because it is kind of command.
 * is called in parser.
 */
class Sleep : public Command {
  public:
    virtual int execute(vector<string> &tokens, int curr_index);

};
#endif //EX3_SLEEP_H
