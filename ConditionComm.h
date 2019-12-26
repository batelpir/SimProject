//
// Created by batel on 26/12/2019.
//

#ifndef EX3__CONDITIONCOMM_H_
#define EX3__CONDITIONCOMM_H_
#include <string>
#include <vector>
#include "Functions.h"
using namespace std;
class ConditionComm {
 protected:
  string condition;

 public:
  bool check_condition();
  vector<string> makeSubTokens(vector<string> tokens, int index_of_begin);
  // helper function:
  void sidesCalculate(int posOfOperator, int operator_len, double& side1_value , double& side2_value);
};
#endif //EX3__CONDITIONCOMM_H_
