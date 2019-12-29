//
// Created by batel on 19/12/2019.
//

#ifndef EX3__UPDATINGCOMMAND_H_
#define EX3__UPDATINGCOMMAND_H_
#include "Command.h"
#include "Singleton.h"
#include "Functions.h"
#include <regex>

class UpdatingCommand: public Command {
  string expression_string;
  string var_name;
  //vector<string> tokens;

 public:
  //UpdatingCommand(vector<string> tokens_input);
  virtual int execute(vector<string> &tokens, int curr_index);
};
#endif //EX3__UPDATINGCOMMAND_H_
