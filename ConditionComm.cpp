//
// Created by batel on 26/12/2019.
//
#include "ConditionComm.h"
#include "Functions.h"

/*
 * check condition - return true if the condition
 * is happening or false if not.
 * sides calculate - helps to "check condition" function
 * to calculate the numeric value of each side in the condition
 */

bool ConditionComm::check_condition() {
  // erase all spaces from the string
  condition.erase(remove(condition.begin(), condition.end(), ' '), condition.end());
  // here the values of each side will be.
  double side1_value, side2_value;
  // check every possible delimiter
  int pos = condition.find("==");
  if (pos != -1) {
    this->sidesCalculate(pos, 2 , side1_value, side2_value );
    if (side1_value == side2_value) {
      return true;
    }
  } else {
    pos = condition.find("<=");
    if (pos != -1) {
      this->sidesCalculate(pos, 2, side1_value, side2_value);
      if(side1_value <= side2_value) {
        return true;
      }
    } else {
      pos = condition.find(">=");
      if(pos != -1) {
        this->sidesCalculate(pos, 2, side1_value,side2_value);
        if(side1_value >= side2_value) {
          return true;
        }
      } else {
        pos = condition.find("!=");
        if(pos != -1) {
          this->sidesCalculate(pos, 2 ,side1_value,side2_value);
          if(side1_value != side2_value) {
            return true;
          }
        } else {
          pos = condition.find("<");
          if(pos != -1) {
            this->sidesCalculate(pos, 1 ,side1_value,side2_value);
            if(side1_value < side2_value) {
              return true;
            }
          } else {
            pos = condition.find(">");
            if(pos != -1) {
              this->sidesCalculate(pos, 1, side1_value, side2_value);
              if (side1_value > side2_value) {
                return true;
              }
            }
          }
        }
      }
    }
  }
  // if has not returned true so far.
  return false;
}

void ConditionComm::sidesCalculate( int posOfOperator, int operator_len, double& side1_value , double& side2_value) {
  string side1 = condition.substr(0, posOfOperator);
  string side2 = condition.substr(posOfOperator + operator_len);
  // changing it also outside the scope
  side1_value = Functions::shuntingYard(side1);
  side2_value = Functions::shuntingYard(side2);
}
