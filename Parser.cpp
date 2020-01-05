//
// Created by batel on 18/12/2019.
//
#include "Parser.h"
#include "Singleton.h"
/*
 * execute each command.
 */
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

      } else if (tokens[index + 1] == "="){ // for '=' case.
        index++;
      } else { // the case that comm is null and a name of function
        // only add the command to the commands map:
        FuncCommand *funcCommand = new FuncCommand();
        // updates the tokens of the function
        vector<string> sub_tokens = funcCommand->makeSubTokens(tokens, index + 3);
        funcCommand->setTokensToScope(sub_tokens);
        // updates the variable name which will be used in the func.
        string var_name = tokens[index + 1].substr(4, tokens[index + 1].length() - 4);
        funcCommand->setVarName(var_name);
        singleton->insertToCommandTable(tokens[index], funcCommand);
        index += 4 + sub_tokens.size();
      }

  }

}
