//
// Created by batel on 18/12/2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_

#include <string>
#include <unordered_map>
#include <vector>
#include <thread>
#include <list>
#include "Var.h"
#include "Command.h"
#include "OpenDataServerCommand.h"
#include "ConnectControlClientCommand.h"
#include "DefineVarCommand.h"
#include "UpdatingCommand.h"
#include "Print.h"
#include "Sleep.h"
#include "WhileCommand.h"
#include "IfCommand.h"

using namespace std;
class Singleton {
  static Singleton *instance;
  unordered_map<string, Var*> symbol_table;
  unordered_map<string, Var*> sim_table;
  unordered_map<int, string> index_table;
  unordered_map<string,Command*> command_table;
  vector<thread*> threads;
  list<string> stringsToSim;

  // Private constructor so that no objects can be created.
  Singleton();

 public:
  // Static access method.
  static Singleton* getInstance();
  void insertToSymbolTable(string s, Var *v);
  void insertToCommandTable(string s, Command *c);
  void insertToSimTable(string s, Var *v);
  Var* getfromSymbolTable(string key);
  Var* getfromSimTable(string key);
  Command* getfromCommandTable(string key);
  unordered_map<string, Var*> getSimTable();
  list<string> getStringsToSim();
  void insertStringsToSim(string s);
  vector<thread*> getThreads();
  unordered_map<int, string> getIndexTable();
  void setToTreads(thread *t);
  string getFromIndexTable(int key);

};

#endif //EX3__SINGLETON_H_
