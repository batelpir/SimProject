//
// Created by batel on 26/12/2019.
//

#ifndef EX3__WHILECOMMAND_H_
#define EX3__WHILECOMMAND_H_
#include "Command.h"
#include "Functions.h"
#include "Parser.h"
#include "ConditionComm.h"
class WhileCommand : public Command , public ConditionComm {

 public:
  virtual int execute(vector<string> &tokens, int curr_index);

};


#endif //EX3__WHILECOMMAND_H_
