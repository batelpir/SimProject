//
// Created by batel on 19/12/2019.
//

#ifndef EX3__VARIABLE_H_
#define EX3__VARIABLE_H_
#include "Expression.h"
#include <string>
class Variable: public Expression {
  double value;
  string name;

 public:
  Variable(string name, double value);
  Variable&operator++();
  Variable&operator--();
  Variable&operator+=(double d);
  Variable&operator-=(double d);
  Variable&operator++(int i);
  Variable&operator--(int i);
  double calculate();
};


#endif //EX3__VARIABLE_H_
