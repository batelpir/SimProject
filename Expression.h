//
// Created by batel on 19/12/2019.
//

#ifndef EX3__EXPRESSION_H_
#define EX3__EXPRESSION_H_

using namespace std;
/**
 * Expression Interface
 */
class Expression {

 public:
  virtual double calculate() = 0;
  virtual ~Expression() {}
};

#endif //EX3__EXPRESSION_H_
