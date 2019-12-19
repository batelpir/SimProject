//
// Created by batel on 19/12/2019.
//

#ifndef EX3__INTERPRETER_H_
#define EX3__INTERPRETER_H_
#include "Expression.h"
#include "Plus.h"
#include "Value.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "UMinus.h"
#include "UPlus.h"
#include "Variable.h"
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <regex>
using namespace std;

class Interpreter {
  map<string, double> variables;
 public:
  Expression* interpret(string str);
  void setVariables(string string1);
};

#endif //EX3__INTERPRETER_H_
