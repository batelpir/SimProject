//
// Created by batel on 19/12/2019.
//
/*
 * calculate - return the value after the division.
 */
#include "Div.h"
double Div::calculate() {
  if( this->left->calculate() == 0){
    throw "error - try to divide by 0";
  }
  return this->right->calculate() / this->left->calculate();
}
Div::~Div() {
  delete this->right;
  delete this->left;
}