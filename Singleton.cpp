//
// Created by batel on 19/12/2019.
//
#include "Singleton.h"

// Null, because instance will be initialized on demand.
Singleton* Singleton::instance = 0;

Singleton :: Singleton(/*vector<string> tokens*/) {
    Var* var_ptr = nullptr;
    //Var* v = new Var();
    //Var* p = new Var();
    // insert to sim table
    sim_table.insert({"/instrumentation/airspeed-indicator/indicated-speed-kt", new Var()});
    sim_table.insert({"/sim/time/warp", new Var()});
    sim_table.insert({"/controls/switches/magneto", new Var()});
    sim_table.insert({"/instrumentation/heading-indicator/offset-deg", new Var()});
    sim_table.insert({"/instrumentation/altimeter/indicated-altitude-ft", new Var()});
    sim_table.insert({"/instrumentation/altimeter/pressure-alt-ft", new Var()});
    sim_table.insert({"/instrumentation/attitude-indicator/indicated-pitch-deg", new Var()});
    sim_table.insert({"/instrumentation/attitude-indicator/indicated-roll-deg", new Var()});
    sim_table.insert({"/instrumentation/attitude-indicator/internal-pitch-deg", new Var()});
    sim_table.insert({"instrumentation/attitude-indicator/internal-roll-deg", new Var()});
    sim_table.insert({"/instrumentation/encoder/indicated-altitude-ft", new Var()});
    sim_table.insert({"/instrumentation/gps/indicated-ground-speed-kt", new Var()});
    sim_table.insert({"/instrumentation/gps/indicated-vertical-speed", new Var()});
    sim_table.insert({"/instrumentation/heading-indicator/indicated-heading-deg", new Var()});
    sim_table.insert({"/instrumentation/magnetic-compass/indicated-heading-deg", new Var()});
    sim_table.insert({"/instrumentation/slip-skid-ball/indicated-slip-skid", new Var()});
    sim_table.insert({"/instrumentation/turn-indicator/indicated-turn-rate", new Var()});
    sim_table.insert({"/instrumentation/vertical-speed-indicator/indicated-speed-fpm", new Var()});
    sim_table.insert({"/controls/flight/aileron", new Var()});
    sim_table.insert({"flight_elevator", new Var()});
    sim_table.insert({"flight_rudder", new Var()});
    sim_table.insert({"/controls/flight/rudder", new Var()});
    sim_table.insert({"/controls/flight/flaps", new Var()});
    sim_table.insert({"/controls/engines/engine/throttle", new Var()});
    sim_table.insert({"/controls/engines/current-engine/throttle", new Var()});
    sim_table.insert({"/controls/switches/master-avionics", new Var()});
    sim_table.insert({"/controls/switches/starter", new Var()});
    sim_table.insert({"active-engine_auto-start", new Var()});
    sim_table.insert({"/engines/active-engine/auto-start", new Var()});
    sim_table.insert({"/controls/flight/speedbrake", new Var()});
    sim_table.insert({"/sim/model/c172p/brake-parking", new Var()});
    sim_table.insert({"/controls/engines/engine/primer", new Var()});
    sim_table.insert({"/controls/engines/current-engine/mixture", new Var()});
    sim_table.insert({"switches_master-bat", new Var()});
    sim_table.insert({"/controls/switches/master-alt", new Var()});
    sim_table.insert({"/engines/engine/rpm", new Var()});
    // insert to command table
    command_table.insert({"openDataServer", new OpenDataServerCommand()});
    command_table.insert({"connectControlClient", new ConnectControlClientCommand()});
    command_table.insert({"var", new DefineVarCommand()});
    command_table.insert({"Print", new Print()});
    command_table.insert({"Sleep", new Sleep()});
    command_table.insert({"=", new UpdatingCommand()});

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

