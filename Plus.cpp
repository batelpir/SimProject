//
// Created by batel on 19/12/2019.
//
#include "Plus.h"
/*
 * calculate - return the the sum between two numbers.
 */
double Plus::calculate() {
  return this->right->calculate() + this->left->calculate();
}
Plus::~Plus() {
  delete this->right;
  delete this->left;
}