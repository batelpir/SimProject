//
// Created by batel on 19/12/2019.
//
#include "Minus.h"
/*
 * calculate - return the value after the reduction.
 */
double Minus::calculate() {
  return this->right->calculate() - this->left->calculate();
}
Minus::~Minus() {
  delete this->right;
  delete this->left;
}