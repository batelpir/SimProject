//
// Created by batel on 19/12/2019.
//

#ifndef EX3__PLUS_H_
#define EX3__PLUS_H_
#include "BinaryOperator.h"
class Plus: public BinaryOperator{
 public:
  Plus(Expression *exp1, Expression *exp2){
    right= exp1;
    left=exp2;
  }
  double calculate();
  virtual ~Plus();
};

#endif //EX3__PLUS_H_
