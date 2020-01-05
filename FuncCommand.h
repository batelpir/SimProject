//
// Created by batel on 02/01/2020.
//

#ifndef EX3__FUNCCOMMAND_H_
#define EX3__FUNCCOMMAND_H_
#include "Functions.h"
#include "SeparateScopeComm.h"
/*
 * the command which run a function.
 * is inherit Command because it is kind of command.
 * is called in parser.
 */
class FuncCommand :public SeparateScopeComm , public Command {
  vector<string> tokens_to_scope;
  string var_name;
 public:
  virtual int execute(vector<string> &tokens, int curr_index);
  void setTokensToScope(vector<string>& tokens);
  void setVarName(string name);
};
#endif //EX3__FUNCCOMMAND_H_
