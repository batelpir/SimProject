//
// Created by batel on 19/12/2019.
//
/*
 * Binary Operator class:
 * is inheriting the Expression class and introducing binary expressions.
 */
#ifndef EX3__BINARYOPERATOR_H_
#define EX3__BINARYOPERATOR_H_
#include "Expression.h"
class BinaryOperator: public Expression {
 protected:
  // sides of the binary expression
  Expression *right, *left;
};

#endif //EX3__BINARYOPERATOR_H_
