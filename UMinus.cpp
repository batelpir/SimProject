//
// Created by batel on 19/12/2019.
//
#include "UMinus.h"
double UMinus::calculate() {
  return -1 * this->exp->calculate();
}
UMinus::~UMinus() {
  delete this->exp;
}