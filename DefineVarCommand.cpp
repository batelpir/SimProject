//
// Created by shaked on 20/12/2019.
//

#include "DefineVarCommand.h"
#include "Singleton.h"

int DefineVarCommand :: execute(vector<string> &tokens, int curr_index) {
  // if it's new var - enter it to symbol table and sim table
  if(tokens[curr_index + 2] == "=") {
    return 1;
  }
  Singleton* singleton = Singleton::getInstance();
  Var* var;
  string sim_name = tokens[curr_index + 4].substr(1, tokens[curr_index + 4].length() - 2);
  var = singleton->getSimTable()[sim_name];
  var->setDirection(tokens[curr_index + 2]);
  var->setSimName(tokens[curr_index + 4]);
  // update var in symbol table and sim table
  singleton->insertToSymbolTable(tokens[curr_index + 1], var);
  singleton->insertToSimTable(tokens[curr_index + 4], var);
  return 5;
}