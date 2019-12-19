#include "UpdatingCommand.h"
#include "Command.h"
#include "Singleton.h"

//
// Created by batel on 19/12/2019.
//
UpdatingCommand::UpdatingCommand(vector<string> tokens_input) {
  this->tokens = tokens_input;
}

int UpdatingCommand::execute(int index) {
  expression = tokens[index + 1];
  var_name = tokens[index - 1];
  Singleton* singleton = Singleton::getInstance();

// check if expression is already a number
  string temp_expression = expression; // make a copy because its helps to check if expression is a negative number
  regex is_num("[0-9]+\\.[0-9]+|[0-9]+");
  // if the Expression is a negative number:
  if(temp_expression[0] == '-') {
    temp_expression.erase(0, 1);
  }
  if(regex_match(temp_expression, is_num)) {
    double value = stod(expression);
    // update the var that in the map.
    Var *var = singleton ->getfromSymbolTable(var_name);
    var->setValue(value);
  }

  // now it is the case that expression isnt a pure number.
  string variable = "";
  regex is_var_name("[A-Za-z_][A-Za-z0-9_]*");
  // passing each char in the expression and try to find variables there.
  for(int i = 0; i < expression.size(); i++) {
    // convert the char to be a string
    string s(1, expression[i]);
    // if the char is a letter or _ so it is a part from the variable name
    if(regex_match(s,is_var_name)) {
      variable += s; // add the char to variable name.
    }
  }
  // להפוך את כל הביטוי למספר ואז להשים אותו במפה .
}
