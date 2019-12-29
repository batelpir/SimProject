//
// Created by batel on 19/12/2019.
//
#include "Singleton.h"

// Null, because instance will be initialized on demand.
Singleton* Singleton::instance = 0;

Singleton :: Singleton() {
    //insert to index table:
    index_table.insert({0, "/instrumentation/airspeed-indicator/indicated-speed-kt"});
    index_table.insert({1, "/sim/time/warp"});
    index_table.insert({2, "/controls/switches/magnetos"});
    index_table.insert({3, "/instrumentation/heading-indicator/offset-deg"});
    index_table.insert({4, "/instrumentation/altimeter/indicated-altitude-ft"});
    index_table.insert({5, "/instrumentation/altimeter/pressure-alt-ft"});
    index_table.insert({6, "/instrumentation/attitude-indicator/indicated-pitch-deg"});
    index_table.insert({7, "/instrumentation/attitude-indicator/indicated-roll-deg"});
    index_table.insert({8, "/instrumentation/attitude-indicator/internal-pitch-deg"});
    index_table.insert({9, "instrumentation/attitude-indicator/internal-roll-deg"});
    index_table.insert({10, "/instrumentation/encoder/indicated-altitude-ft"});
    index_table.insert({11, "/instrumentation/encoder/pressure-alt-ft"});
    index_table.insert({12, "/instrumentation/gps/indicated-altitude-ft"});
    index_table.insert({13, "/instrumentation/gps/indicated-ground-speed-kt"});
    index_table.insert({14, "/instrumentation/gps/indicated-vertical-speed"});
    index_table.insert({15, "/instrumentation/heading-indicator/indicated-heading-deg"});
    index_table.insert({16, "/instrumentation/magnetic-compass/indicated-heading-deg"});
    index_table.insert({17, "/instrumentation/slip-skid-ball/indicated-slip-skid"});
    index_table.insert({18, "/instrumentation/turn-indicator/indicated-turn-rate"});
    index_table.insert({19, "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"});
    index_table.insert({20, "/controls/flight/aileron"});
    index_table.insert({21, "/controls/flight/elevator"});
    index_table.insert({22, "/controls/flight/rudder"});
    index_table.insert({23, "/controls/flight/flaps"});
    index_table.insert({24, "/controls/engines/engine/throttle"});
    index_table.insert({25, "/controls/engines/current-engine/throttle"});
    index_table.insert({26, "/controls/switches/master-avionics"});
    index_table.insert({27, "/controls/switches/starter"});
    index_table.insert({28, "/engines/active-engine/auto-start"});
    index_table.insert({29, "/controls/flight/speedbrake"});
    index_table.insert({30, "/sim/model/c172p/brake-parking"});
    index_table.insert({31, "/controls/engines/engine/primer"});
    index_table.insert({32, "/controls/engines/current-engine/mixture"});
    index_table.insert({33, "/controls/switches/master-bat"});
    index_table.insert({34, "/controls/switches/master-alt"});
    index_table.insert({35, "/engines/engine/rpm"});

    // insert to sim table
    sim_table.insert({"/instrumentation/airspeed-indicator/indicated-speed-kt", new Var()});
    sim_table.insert({"/sim/time/warp", new Var()});
    sim_table.insert({"/controls/switches/magnetos", new Var()});
    sim_table.insert({"/instrumentation/heading-indicator/offset-deg", new Var()});
    sim_table.insert({"/instrumentation/altimeter/indicated-altitude-ft", new Var()});
    sim_table.insert({"/instrumentation/altimeter/pressure-alt-ft", new Var()});
    sim_table.insert({"/instrumentation/attitude-indicator/indicated-pitch-deg", new Var()});
    sim_table.insert({"/instrumentation/attitude-indicator/indicated-roll-deg", new Var()});
    sim_table.insert({"/instrumentation/attitude-indicator/internal-pitch-deg", new Var()});
    sim_table.insert({"instrumentation/attitude-indicator/internal-roll-deg", new Var()});
    sim_table.insert({"/instrumentation/encoder/indicated-altitude-ft", new Var()});
    sim_table.insert({"/instrumentation/encoder/pressure-alt-ft", new Var()});
    sim_table.insert({"/instrumentation/gps/indicated-altitude-ft", new Var()});
    sim_table.insert({"/instrumentation/gps/indicated-ground-speed-kt", new Var()});
    sim_table.insert({"/instrumentation/gps/indicated-vertical-speed", new Var()});
    sim_table.insert({"/instrumentation/heading-indicator/indicated-heading-deg", new Var()});
    sim_table.insert({"/instrumentation/magnetic-compass/indicated-heading-deg", new Var()});
    sim_table.insert({"/instrumentation/slip-skid-ball/indicated-slip-skid", new Var()});
    sim_table.insert({"/instrumentation/turn-indicator/indicated-turn-rate", new Var()});
    sim_table.insert({"/instrumentation/vertical-speed-indicator/indicated-speed-fpm", new Var()});
    sim_table.insert({"/controls/flight/aileron", new Var()});
    sim_table.insert({"/controls/flight/elevator", new Var()});
    sim_table.insert({"/controls/flight/rudder", new Var()});
    sim_table.insert({"/controls/flight/flaps", new Var()});
    sim_table.insert({"/controls/engines/engine/throttle", new Var()});
    sim_table.insert({"/controls/engines/current-engine/throttle", new Var()});
    sim_table.insert({"/controls/switches/master-avionics", new Var()});
    sim_table.insert({"/controls/switches/starter", new Var()});
    sim_table.insert({"/engines/active-engine/auto-start", new Var()});
    sim_table.insert({"/controls/flight/speedbrake", new Var()});
    sim_table.insert({"/sim/model/c172p/brake-parking", new Var()});
    sim_table.insert({"/controls/engines/engine/primer", new Var()});
    sim_table.insert({"/controls/engines/current-engine/mixture", new Var()});
    sim_table.insert({"/controls/switches/master-bat", new Var()});
    sim_table.insert({"/controls/switches/master-alt", new Var()});
    sim_table.insert({"/engines/engine/rpm", new Var()});
    // insert to command table

    command_table.insert({"openDataServer", new OpenDataServerCommand()});
    command_table.insert({"connectControlClient", new ConnectControlClientCommand()});

    command_table.insert({"var", new DefineVarCommand()});

    command_table.insert({"Print", new Print()});

    command_table.insert({"Sleep", new Sleep()});

    command_table.insert({"=", new UpdatingCommand()});
    command_table.insert({"while", new WhileCommand()});
    command_table.insert({"if", new IfCommand()});

    // if and while conditions need to be added here
    ///////////////////////////////////////////////////
    /*
    Var* var = new Var();
    var->setValue(7);
    symbol_table.insert({"va", var});

    Var* var1 = new Var();
    //var1->setValue(4);
    symbol_table.insert({"var1", var1});

    Var* var2 = new Var();
    //var2->setValue(5);
    symbol_table.insert({"var2", var2});
     */
    //////////////////////////////////////
}

Singleton* Singleton::getInstance() {
  if (instance == 0)
  {
    instance = new Singleton();
  }

  return instance;
}

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
// delete. we dont use it...
Var* Singleton::getfromSimTable(string key) {
  return this ->sim_table[key];
}

Command* Singleton::getfromCommandTable(string key) {
  return this ->command_table[key];
}

unordered_map<string, Var*> Singleton::getSimTable() {
  return this->sim_table;
}

list<string> Singleton::getStringsToSim() {
    return this->stringsToSim;
}
void Singleton::insertStringsToSim(string s) {
    this->stringsToSim.push_back(s);
}

void Singleton::setToTreads(thread *t) {
  this->threads.emplace_back(t);
}

vector<thread*> Singleton::getThreads() {
    return this->threads;
}

unordered_map<int, string> Singleton::getIndexTable() {
  return this->index_table;
}
string Singleton::getFromIndexTable(int key) {
  return this->index_table[key];
}

