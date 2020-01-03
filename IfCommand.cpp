//
// Created by batel on 25/12/2019.
//
#include "IfCommand.h"
/*
 * execute - checks if the condition is true and
 * accordingly to it executes all the commands that are into the 'if' scope.
 */
int IfCommand::execute(vector<string> &tokens, int curr_index) {
  this->condition = tokens[curr_index + 1];
  vector<string> sub_tokens = makeSubTokens(tokens, curr_index + 3);
  if(this->check_condition()) {
    Parser *parser = new Parser(sub_tokens);
    parser -> parser();
    delete parser;
  }
  return 4 + sub_tokens.size();
}
