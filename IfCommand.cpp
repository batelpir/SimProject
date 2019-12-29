//
// Created by batel on 25/12/2019.
//
#include "IfCommand.h"
int IfCommand::execute(vector<string> &tokens, int curr_index) {
  this->condition = tokens[curr_index + 1];

  vector<string> sub_tokens = makeSubTokens(tokens, curr_index + 3);
  if(this->check_condition()) {
    Parser *parser = new Parser(sub_tokens);
    parser -> parser();
    delete parser;
  }
  return curr_index + 4 + sub_tokens.size();
}
