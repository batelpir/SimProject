//
// Created by batel on 18/12/2019.
//

#ifndef EX3__VAR_H_
#define EX3__VAR_H_
#include <string>
#include <iostream>
using namespace std;
// like a struct of data about the variable.
class Var {
  double value;
  string simName;
  string arrow;
 public:

  // Setter
  void setValue(double v) {
    //cout<<v<<endl;
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
  void setArrow(string s) {
      this->arrow = s;
  }
  // Getter
  string getArrow() {
      return this->arrow;
  }
};

#endif //EX3__VAR_H_
