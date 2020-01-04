//
// Created by batel on 26/12/2019.
//

#ifndef EX3__CONDITIONCOMM_H_
#define EX3__CONDITIONCOMM_H_

#include <string>
#include <vector>
#include "SeparateScopeComm.h"
/*
 *a class that has behaviors of condition commands.
 * it has a check condition function and also sides calculate
 * to check the numeric value of the sides of the expression
 */
using namespace std;
class ConditionComm : public SeparateScopeComm{
 protected:
  string condition;

 public:
  bool check_condition();
  // helper function:
  void sidesCalculate(int posOfOperator, int operator_len, double& side1_value , double& side2_value);
};
#endif //EX3__CONDITIONCOMM_H_
