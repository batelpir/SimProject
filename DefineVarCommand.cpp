//
// Created by shaked on 20/12/2019.
//

#include "DefineVarCommand.h"
#include "Singleton.h"

/*DefineVarCommand::DefineVarCommand(vector<string> tokens_input) {
    this->tokens = tokens_input;
}*/
int DefineVarCommand :: execute(vector<string> tokens, int curr_index) {
  // if it's new var
  Singleton* instance = Singleton::getInstance();
  Var *var = new Var();

  var->setArrow(tokens[curr_index + 2]);
  var->setSimName(tokens[curr_index + 4]);
  instance->insertToSymbolTable(tokens[curr_index + 1], var);
  instance->insertToSimTable(tokens[curr_index + 4], var);
  return curr_index + 5;

}