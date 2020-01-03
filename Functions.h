//
// Created by batel on 23/12/2019.
//

#ifndef EX3__FUNCTIONS_H_
#define EX3__FUNCTIONS_H_
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>
#include "Expression.h"
#include "Var.h"
#include "Singleton.h"
#include "Interpreter.h"
using namespace std;
/**
 * a class which has static functions that do diverse thinks.
 * "split line" - helps to lexer function to split specific line.
 * "lexer" - splits all the given file into tokens.
 * "shunting yard" - accepts a string that represent some expression and returns its numeric value
 */
class Functions {
 public:
  static void splitLine(vector<string> *tokens, string line, int delim_pos);
  static vector<string> lexer(string file_name);
  static double shuntingYard(string expression_string);
  static void helper(ifstream &file_obj, vector<string> *tokens, string line);
};
#endif //EX3__FUNCTIONS_H_
