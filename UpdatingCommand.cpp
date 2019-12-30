#include "UpdatingCommand.h"

//
// Created by batel on 19/12/2019.
//

int UpdatingCommand::execute(vector<string> &tokens, int index) {
  expression_string = tokens[index + 1];
  var_name = tokens[index - 1];
  //cout<<var_name<<endl;
  Singleton* singleton = Singleton::getInstance();
  double val = Functions::shuntingYard(expression_string);
  // update the var that in the map.
  Var *var = singleton->getfromSymbolTable(var_name);
  var->setValue(val);
  if(var->getSimName() != "") {
      string temp_sim_name = singleton->getfromSymbolTable(var_name)->getSimName();
      string sim_name = temp_sim_name.substr(1, temp_sim_name.length() - 2);
      string string_to_sim = sim_name + " " + to_string(singleton->getfromSymbolTable(var_name)->getValue());
      //cout << string_to_sim << endl;
      singleton->insertStringsToSim(string_to_sim);
  }
  return 2;
}
