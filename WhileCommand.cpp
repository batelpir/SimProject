//
// Created by batel on 26/12/2019.
//
#include "WhileCommand.h"

int WhileCommand::execute(vector<string> tokens, int curr_index) {
  this->condition = tokens[curr_index + 1];
  vector<string> sub_tokens = this->makeSubTokens(tokens, curr_index + 3);
  Parser* parser = new Parser(sub_tokens);
  while(this ->check_condition()) {
    parser->parser();
  }
  delete(parser);
  return curr_index + 4 +sub_tokens.size();
}