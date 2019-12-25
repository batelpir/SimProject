//
// Created by batel on 19/12/2019.
//
#include "Singleton.h"

// Null, because instance will be initialized on demand.
Singleton* Singleton::instance = 0;

Singleton :: Singleton(/*vector<string> tokens*/) {
    Var* var_ptr = nullptr;
    // insert to sim table
    symbol_table.insert({"/instrumentation/airspeed-indicator/indicated-speed-kt", nullptr});
    symbol_table.insert({"/sim/time/warp", nullptr});
    symbol_table.insert({"/controls/switches/magneto", nullptr});
    symbol_table.insert({"/instrumentation/heading-indicator/offset-deg", nullptr});
    symbol_table.insert({"/instrumentation/altimeter/indicated-altitude-ft", nullptr});
    symbol_table.insert({"/instrumentation/altimeter/pressure-alt-ft", nullptr});
    symbol_table.insert({"/instrumentation/attitude-indicator/indicated-pitch-deg", nullptr});
    symbol_table.insert({"/instrumentation/attitude-indicator/indicated-roll-deg", nullptr});
    symbol_table.insert({"/instrumentation/attitude-indicator/internal-pitch-deg", nullptr});
    symbol_table.insert({"instrumentation/attitude-indicator/internal-roll-deg", nullptr});
    symbol_table.insert({"/instrumentation/encoder/indicated-altitude-ft", nullptr});
    symbol_table.insert({"/instrumentation/gps/indicated-ground-speed-kt", nullptr});
    symbol_table.insert({"/instrumentation/gps/indicated-vertical-speed", nullptr});
    symbol_table.insert({"/instrumentation/heading-indicator/indicated-heading-deg", nullptr});
    symbol_table.insert({"/instrumentation/magnetic-compass/indicated-heading-deg", nullptr});
    symbol_table.insert({"/instrumentation/slip-skid-ball/indicated-slip-skid", nullptr});
    symbol_table.insert({"/instrumentation/turn-indicator/indicated-turn-rate", nullptr});
    symbol_table.insert({"/instrumentation/vertical-speed-indicator/indicated-speed-fpm", nullptr});
    symbol_table.insert({"/controls/flight/aileron", nullptr});
    symbol_table.insert({"flight_elevator", nullptr});
    symbol_table.insert({"flight_rudder", nullptr});
    symbol_table.insert({"/controls/flight/rudder", nullptr});
    symbol_table.insert({"/controls/flight/flaps", nullptr});
    symbol_table.insert({"/controls/engines/engine/throttle", nullptr});
    symbol_table.insert({"/controls/engines/current-engine/throttle", nullptr});
    symbol_table.insert({"/controls/switches/master-avionics", nullptr});
    symbol_table.insert({"/controls/switches/starter", nullptr});
    symbol_table.insert({"active-engine_auto-start", nullptr});
    symbol_table.insert({"/engines/active-engine/auto-start", nullptr});
    symbol_table.insert({"/controls/flight/speedbrake", nullptr});
    symbol_table.insert({"/sim/model/c172p/brake-parking", nullptr});
    symbol_table.insert({"/controls/engines/engine/primer", nullptr});
    symbol_table.insert({"/controls/engines/current-engine/mixture", nullptr});
    symbol_table.insert({"switches_master-bat", nullptr});
    symbol_table.insert({"/controls/switches/master-alt", nullptr});
    symbol_table.insert({"/engines/engine/rpm", nullptr});

    // insert to command table
    command_table.insert({"openDataServer", new OpenDataServerCommand()});
    command_table.insert({"connectControlClient", new ConnectControlClientCommand()});
    command_table.insert({"var", new DefineVarCommand()});
    command_table.insert({"Print", new Print()});
    command_table.insert({"Sleep", new Sleep()});
    command_table.insert({"=", new UpdatingCommand()});

    // if and while conditions need to be added here
    ///////////////////////////////////////////////////
    Var* var = new Var();
    var->setValue(6);
    symbol_table.insert({"var", var});

    Var* var1 = new Var();
    var1->setValue(5);
    symbol_table.insert({"h0", var1});

    Var* var2 = new Var();
    var2->setValue(4);
    symbol_table.insert({"lol", var2});
    //////////////////////////////////////
}

Singleton* Singleton::getInstance(/*vector<string> tokens*/) {
  if (instance == 0)
  {
    instance = new Singleton(/*tokens*/);
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

map<string, Var*> Singleton::getSimTable() {
  return this->sim_table;
}

list<string> Singleton::getStringsToSim() {
    return this->stringsToSim;
}
void Singleton::insertStringsToSim(string s) {
    this->stringsToSim.push_back(s);
}


vector<thread*> Singleton::getThreads() {
    return this->threads;
}



