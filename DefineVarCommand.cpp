//
// Created by shaked on 20/12/2019.
//

#include "DefineVarCommand.h"
#include "Singleton.h"

int DefineVarCommand :: execute(vector<string> &tokens, int curr_index) {
  // if it's new var - enter it to symbol table and sim table
  Singleton* singleton = Singleton::getInstance();
  Var* var;
  var = singleton->getSimTable()[tokens[curr_index + 4]];
  var->setDirection(tokens[curr_index + 2]);
  var->setSimName(tokens[curr_index + 4]);
  // update var in symbol table and sim table
  singleton->insertToSymbolTable(tokens[curr_index + 1], var);
  singleton->insertToSimTable(tokens[curr_index + 4], var);
  return curr_index + 5;

}