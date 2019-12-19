//
// Created by batel on 19/12/2019.
//

#ifndef EX3__MUL_H_
#define EX3__MUL_H_
#include "BinaryOperator.h"
class Mul: public BinaryOperator{
 public:
  Mul(Expression *exp1, Expression *exp2) {
    right = exp1;
    left = exp2;
  }
  double calculate();
  virtual ~Mul();
};

#endif //EX3__MUL_H_
