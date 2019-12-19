//
// Created by batel on 19/12/2019.
//

#ifndef EX3__MINUS_H_
#define EX3__MINUS_H_
#include "BinaryOperator.h"
class Minus: public BinaryOperator{
 public:
  Minus(Expression *exp1, Expression *exp2){
    right = exp1;
    left = exp2;
  }
  double calculate();
  virtual ~Minus();
};


#endif //EX3__MINUS_H_
