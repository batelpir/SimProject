//
// Created by batel on 18/12/2019.
//

#ifndef EX3__PARSER_H_
#define EX3__PARSER_H_
#include <string>
#include <vector>
#include "FuncCommand.h"
/*
 * parse each command accordingly the tokens
 * which given to him in the constructor
 */
using namespace std;
class Parser {
 private:
  vector<string> tokens;
 public:
  Parser(vector<string> tokens_input);
  void parser();

};

#endif //EX3__PARSER_H_
