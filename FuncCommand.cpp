//
// Created by batel on 02/01/2020.
//
#include "FuncCommand.h"
/*
 * 'execute' - runs the function with an argument which given.
 */
int FuncCommand::execute(vector<string> &tokens, int curr_index) {
  Singleton* singleton = Singleton::getInstance();
  Var *parameter = new Var();
  // get the numeric value of the argument which given
  double val = Functions::shuntingYard(tokens[curr_index + 1]);
  parameter->setValue(val);
  // put the parameter in symbol table.
  singleton->insertToSymbolTable(var_name, parameter);
  //run the function's commands.
  Parser* p = new Parser(this->tokens_to_scope);
  p->parser();
  delete p;
  return 2;
}

void FuncCommand::setTokensToScope(vector<string> &tokens) {
  this->tokens_to_scope = tokens;
}

void FuncCommand::setVarName(string name) {
  this->var_name = name;
}