//
// Created by batel on 18/12/2019.
//

#ifndef EX3__SINGLETON_H_
#define EX3__SINGLETON_H_

#include <string>
#include <map>
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


using namespace std;
class Singleton {
  static Singleton *instance;
  map<string, Var*> symbol_table;
  map<string, Var*> sim_table;
  unordered_map<string,Command*> command_table;
  thread *connectClientThread;
  thread *openServerThread;
  //vector<thread> threads;
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
  map<string, Var*> getSimTable();
  list<string> getStringsToSim();
  void insertStringsToSim(string s);
  thread* getClientThread();
  //void insertThread(thread t);

    //void insertThread(thread t);
};

#endif //EX3__SINGLETON_H_
