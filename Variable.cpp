//
// Created by batel on 19/12/2019.
//
#include "Variable.h"
Variable& Variable::operator++(){
  this->value++;
  return *this;
}
Variable& Variable::operator--(){
  this->value--;
  return *this;
}
Variable& Variable::operator+=(double d){
  this->value+= d;
  return *this;
}
Variable& Variable::operator-=(double d){
  this->value-= d;
  return *this;
}
Variable& Variable::operator++(int){
  this->value++;
  return *this;
}
Variable& Variable::operator--(int){
  this->value--;
  return *this;
}
double Variable::calculate(){
  return this->value;
}
Variable::Variable(string varName, double varValue) {
  //check the name.
  //if(name.at(0) != )
  this->value = varValue;
  this->name = varName;
}