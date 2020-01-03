//
// Created by shaked on 20/12/2019.
//

#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H
#include "Command.h"
#include "Var.h"
/*
 * the command which creates vars and enter them into symbol and sim maps.
 * is inherit Command because it is kind of command.
 * is called in parser.
 */
class DefineVarCommand : public Command {
public:
    virtual int execute(vector<string> &tokens, int curr_index);
};


#endif //EX3_DEFINEVARCOMMAND_H
