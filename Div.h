//
// Created by batel on 19/12/2019.
//

#ifndef EX3__DIV_H_
#define EX3__DIV_H_
#include "BinaryOperator.h"
class Div: public BinaryOperator{
 public:
  // constructor
  Div(Expression *exp1, Expression *exp2) {
    right = exp1;
    left = exp2;
  }
  double calculate();
  virtual ~Div();
};

#endif //EX3__DIV_H_
