//
// Created by batel on 25/12/2019.
//

#ifndef EX3__IFCOMMAND_H_
#define EX3__IFCOMMAND_H_

#include "Parser.h"
#include "ConditionComm.h"
#include "Command.h"
/*
 * the command which called in case we see the 'if' word in the tokens.
 */
class IfCommand : public Command , public ConditionComm{
 public:
  virtual int execute(vector<string> &tokens, int curr_index);
};

#endif //EX3__IFCOMMAND_H_
