//
// Created by batel on 18/12/2019.
//
#include "Parser.h"

Parser::Parser(vector<string> tokens_input) {
  tokens = tokens_input;
}

void Parser::parser() {
  Singleton* singleton = Singleton::getInstance();
  Command* comm;
  int index = 0;

  while(index < tokens.size()) {
      comm = singleton->getfromCommandTable(tokens[index]);
      if (comm != NULL) {
          index += comm->execute(tokens, index);

      }
      index++;
  }

}
