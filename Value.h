//
// Created by batel on 19/12/2019.
//

#ifndef EX3__VALUE_H_
#define EX3__VALUE_H_
#include "Expression.h"
/*
 * represent a value (a number).
 */
class Value: public Expression{
  double val;
 public:
  Value(double value) : val(value) {}
  double calculate();
};

#endif //EX3__VALUE_H_
