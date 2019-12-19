//
// Created by batel on 19/12/2019.
//

#ifndef EX3__UPLUS_H_
#define EX3__UPLUS_H_
#include "UnaryOperator.h"
class UPlus: public UnaryOperator{
 public:
  UPlus(Expression *expression){
    this->exp = expression;
  }
  double calculate();
  virtual ~UPlus();
};

#endif //EX3__UPLUS_H_
