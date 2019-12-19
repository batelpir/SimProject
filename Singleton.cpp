//
// Created by batel on 19/12/2019.
//
#include "Singleton.h"
// Null, because instance will be initialized on demand.
Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance() {
  if (instance == 0)
  {
    instance = new Singleton();
  }

  return instance;
}

Singleton::Singleton()
{}

void Singleton::insertToSymbolTable(string s, Var *v) {
  this->symbol_table[s] = v;
}

void Singleton::insertToSimTable(string s, Var *v) {
  this->sim_table[s] = v;
}

void Singleton::insertToCommandTable(string s, Command *c) {
  this->command_table[s] = c;
}

Var* Singleton::getfromSymbolTable(string key) {
  return this->symbol_table[key];
}

Var* Singleton::getfromSimTable(string key) {
  return this ->sim_table[key];
}

Command* Singleton::getfromCommandTable(string key) {
  return this ->command_table[key];
}

