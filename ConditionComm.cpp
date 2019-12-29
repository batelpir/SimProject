//
// Created by batel on 26/12/2019.
//
#include "ConditionComm.h"
#include "Functions.h"

//index_begin us the index of the first string after '{'
vector<string> ConditionComm::makeSubTokens(vector<string> tokens, int index_begin) {
  vector<string> sub_tokens;
  int index_end = index_begin;
  while (tokens[index_end] != "}") {
    sub_tokens.push_back(tokens[index_end]);
    index_end++;
  } // now index of end is the index of "}" and sub tokens is done.
  return sub_tokens;
}

bool ConditionComm::check_condition() {
  condition.erase(remove(condition.begin(), condition.end(), ' '), condition.end());
  // here the values of each side will be.
  double side1_value, side2_value;

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
