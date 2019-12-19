//
// Created by batel on 19/12/2019.
//

#ifndef EX3__BINARYOPERATOR_H_
#define EX3__BINARYOPERATOR_H_
#include "Expression.h"
class BinaryOperator: public Expression {
 protected:
  Expression *right, *left;
};

#endif //EX3__BINARYOPERATOR_H_
