//
// Created by batel on 18/12/2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_
#include <string>
#include <map>
#include <unordered_map>
#include "Var.h"
#include "Command.h"
using namespace std;
class Singleton {
  static Singleton *instance;
  map<string, Var> symbolTable;
  map<string, Var> simTable;
  unordered_map<string,Command> commandTable;

  // Private constructor so that no objects can be created.
  Singleton() {}

 public:
  static Singleton *getInstance() {
    if (!instance)
      instance = new Singleton;
    return instance;
  }
  void insertToSymbolTable(string s, Var v) {
    this->symbolTable[s] = v;
  }
  void insertToCommandTable(string s, Command c) {
    this->commandTable[s] = c;
  }
  void insertToSimTable(string s, Var v) {
    this->simTable[s] = v;
  }

  Var getfromSymbolTable(string key) {
    return this->symbolTable[key];
  }
  Var getfromSimTable(string key) {
    return this -> simTable[key];
  }
  Command getfromCommandTable(string key) {
    return this -> commandTable[key];
  }
};

#endif //EX3__SINGLETON_H_
