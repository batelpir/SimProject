//
// Created by batel on 18/12/2019.
//

#ifndef EX3__VAR_H_
#define EX3__VAR_H_
#include <string>
using namespace std;
// like a struct of data about the variable.
class Var {
 private:
  int value;
  string simName;
  // Setter
  void setValue(int v) {
    this->value = v;
  }
  // Getter
  int getValue() {
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
};

#endif //EX3__VAR_H_
