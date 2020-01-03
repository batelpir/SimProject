//
// Created by batel on 26/12/2019.
//

#ifndef EX3__WHILECOMMAND_H_
#define EX3__WHILECOMMAND_H_

#include "Parser.h"
#include "ConditionComm.h"
#include "Command.h"
using namespace std;
/*
 * the command which called in case we see the 'while' word in the tokens
 */
class WhileCommand : public Command,public ConditionComm{

public:
    virtual int execute(vector<string> &tokens, int curr_index);
};


#endif //EX3__WHILECOMMAND_H_
