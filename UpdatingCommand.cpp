#include "UpdatingCommand.h"
#include "Command.h"
//
// Created by batel on 19/12/2019.
//
UpdatingCommand::UpdatingCommand(vector<string> tokens_input) {
  this->tokens = tokens_input;
}

int UpdatingCommand::execute(int index) {
  expression = tokens[index +1];

  string temp_expression = expression; // make a copy because is help to check if expression is a negative number
  regex is_num("[0-9]+\\.[0-9]+|[0-9]+");

  // if the Expression is a negative number:
  if(temp_expression[0] == '-') {
    temp_expression.erase(0, 1);
  }
  if(regex_match(temp_expression, is_num)) {
    double value = stod(expression);

  }
  // passing each char in the expression and try to find variables there.
  for(int i = 0; i < expression.size(); i++) {

  }
  // להפוך את כל הביטוי למספר ואז להשים אותו במפה .
}
