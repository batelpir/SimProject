#include "UpdatingCommand.h"

//
// Created by batel on 19/12/2019.
//

int UpdatingCommand::execute(vector<string> &tokens, int index) {
  expression_string = tokens[index + 1];
  var_name = tokens[index - 1];
  Singleton* singleton = Singleton::getInstance();
  double val = Functions::shuntingYard(expression_string);
  // update the var that in the map.
  Var *var = singleton->getfromSymbolTable(var_name);
  var->setValue(val);
  string string_to_sim = singleton->getfromSymbolTable(var_name)->getSimName() +
      to_string(singleton->getfromSymbolTable(var_name)->getValue());
  singleton->insertStringsToSim(string_to_sim);
  return index + 2;
}
