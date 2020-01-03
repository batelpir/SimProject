//
// Created by batel on 18/12/2019.
//

#ifndef EX3__VAR_H_
#define EX3__VAR_H_
#include <string>
#include <iostream>
using namespace std;

/*
 * contain all the data about a variable that in the file.
 * have also some behaviors to update and get the data.
 */
class Var {
  double value;
  string simName = "";
  string direction = "";
 public:
  // Setter
  void setValue(double v) {
    this->value = v;
  }
  // Getter
  double getValue() {
    return this->value;
  }
  // Setter
  void setSimName(string s) {
    this->simName = s;
  }
  // Getter
  string getSimName() {
      return this->simName;
  }
  // Setter
  void setDirection(string s) {
      this->direction = s;
  }
  // Getter
  string getDirection() {
      return this->direction;
  }
};

#endif //EX3__VAR_H_
