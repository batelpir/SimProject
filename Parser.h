//
// Created by batel on 18/12/2019.
//

#ifndef EX3__PARSER_H_
#define EX3__PARSER_H_
#include <string>
#include <vector>
#include "Singleton.h"
using namespace std;
class Parser {
 private:
  vector<string> *tokens;
 public:
  //Parser(vector<string> *tokens_input);
  Parser(vector<string> &tokens_input);
  void parser();

};

#endif //EX3__PARSER_H_
