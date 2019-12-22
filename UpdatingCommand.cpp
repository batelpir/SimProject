#include "UpdatingCommand.h"

//
// Created by batel on 19/12/2019.
//
/*UpdatingCommand::UpdatingCommand(vector<string> tokens_input) {
  this->tokens = tokens_input;
}*/

int UpdatingCommand::execute(vector<string> tokens, int index) {
  expression_string = /*tokens[index + 1]*/"(h0 - 6) /lol ";
  var_name = /*tokens[index - 1]*/"var";
  Singleton* singleton = Singleton::getInstance();

// check if expression_string is already a number
  string temp_expression = expression_string; // make a copy because its helps to check if expression_string is a negative number
  regex is_num("[0-9]+\\.[0-9]+|[0-9]+");
  // if the Expression is a negative number:
  if(temp_expression[0] == '-') {
    temp_expression.erase(0, 1);
  }
  if(regex_match(temp_expression, is_num)) {
    double value = stod(expression_string);
    // update the var that in the map.
    Var *var = singleton ->getfromSymbolTable(var_name);
    var->setValue(value);
  }

  // now it is the case that expression_string isnt a pure number.
  Interpreter* inter = new Interpreter();
  Expression* exp = nullptr;
  string variable = "";
  regex is_part_of_var_name("[A-Za-z0-9_]");
  regex is_first_char_of_var_name("[A-Za-z_]");
  // passing each char in the expression_string and try to find variables there.
  for(int i = 0; i < expression_string.size(); i++) {
    // convert the char to be a string
    string s(1, expression_string[i]);
    // if the char is a letter or _ so it is can be the first char from the variable name
    if(variable.empty() && regex_match(s ,is_first_char_of_var_name)) {
      variable += s; // add the char to variable name.
    } else {
      // this case mean that the char is a part of a variable name.
      if((!variable.empty()) &&regex_match(s ,is_part_of_var_name)) {
        variable += s; // add the char to variable name.
      } else {
        // mean that we finished to build the name of var and now it is another char.
        // (attention: number will not enter to this case but it will never be the first char after a variable name.)
        if(!variable.empty() && !regex_match(s ,is_part_of_var_name)) {
          // מטפלים בשם משתנה ואז מוחקים.
          Var* variable_data = singleton->getfromSymbolTable(variable);
          double variable_value = variable_data->getValue();
          string value_string = to_string(variable_value);
          try {
            inter->setVariables(variable + "=" + value_string);
            //delete inter;
          } catch (const char* e) {
            //if (inter != nullptr) {
            delete inter;
            //}
          }
          variable = ""; // delete the variable name that we finish to deal with.
        }
      }
    }
    /*
    // this case mean that the char is a part of a variable name.
    if((!variable.empty()) &&regex_match(s ,is_part_of_var_name)) {
      variable += s; // add the char to variable name.
    }
    // mean that we finished to build the name of var and now it is another char.
    // (attention: number will not enter to this case but it will never be the first char after a variable name.)
    if(!variable.empty() && !regex_match(s ,is_part_of_var_name)) {
      // מטפלים בשם משתנה ואז מוחקים.
      Var* variable_data = singleton->getfromSymbolTable(variable);
      double variable_value = variable_data->getValue();
      string value_string = to_string(variable_value);
      try {
        inter->setVariables(variable + "=" + value_string);
        delete inter;
      } catch (const char* e) {
        //if (inter != nullptr) {
          delete inter;
        //}
      }
      variable = ""; // delete the variable name that we finish to deal with.
    } */
  }
  // remove the spaces from the expression_string string.
  expression_string.erase(std::remove(expression_string.begin(), expression_string.end(), ' '), expression_string.end());
  try {
    exp = inter->interpret(expression_string);
    // update the value of var.
    singleton->getfromSymbolTable(var_name)->setValue(exp->calculate());
    delete exp;
  }catch(const char* e) {
    //if (exp != nullptr) {
      delete exp;
    //}
  }
}
