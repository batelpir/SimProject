//
// Created by batel on 18/12/2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_

#include <string>
#include <map>
#include <unordered_map>
#include <vector>

#include "Var.h"
#include "Command.h"
#include "DefineVarCommand.h"
#include "Print.h"
#include "Sleep.h"

using namespace std;
class Singleton {
  static Singleton *instance;
  //vector<string> tokens;
  map<string, Var*> symbol_table;
  map<string, Var*> sim_table;
  unordered_map<string,Command*> command_table;

  // Private constructor so that no objects can be created.
  Singleton(/*vector<string> tokens*/);

 public:
  // Static access method.
  static Singleton* getInstance(/*vector<string> tokens*/);
  //map<string, Var*> getSymbolTable();
  void insertToSymbolTable(string s, Var *v);
  void insertToCommandTable(string s, Command *c);
  void insertToSimTable(string s, Var *v);
  Var* getfromSymbolTable(string key);
  Var* getfromSimTable(string key);
  Command* getfromCommandTable(string key);
};

#endif //EX3__SINGLETON_H_
