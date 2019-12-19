//
// Created by batel on 19/12/2019.
//

#ifndef EX3__UMINUS_H_
#define EX3__UMINUS_H_
#include "UnaryOperator.h"
class UMinus: public UnaryOperator{
 public:
  UMinus(Expression *expression){
    this->exp = expression;
  }
  double calculate();
  virtual ~UMinus();
};

#endif //EX3__UMINUS_H_
