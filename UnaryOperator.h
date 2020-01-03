//
// Created by batel on 19/12/2019.
//

#ifndef EX3__UNARYOPERATOR_H_
#define EX3__UNARYOPERATOR_H_
#include "Expression.h"
/*
 * an interface to unary expressions
 */
class UnaryOperator: public Expression{
 protected:
  Expression *exp;
};

#endif //EX3__UNARYOPERATOR_H_
