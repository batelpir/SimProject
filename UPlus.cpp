//
// Created by batel on 19/12/2019.
//
#include "UPlus.h"

double UPlus::calculate() {
  return this->exp->calculate();
}
UPlus::~UPlus() {
  delete this->exp;
}