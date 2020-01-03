//
// Created by batel on 19/12/2019.
//
#include "Mul.h"
/*
 * calculate - return the value after the multiplication.
 */
double Mul::calculate() {
  return this->right->calculate() * this->left->calculate();
}
Mul::~Mul() {
  delete this->right;
  delete this->left;
}