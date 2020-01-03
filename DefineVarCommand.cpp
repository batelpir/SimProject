//
// Created by shaked on 20/12/2019.
//

#include "DefineVarCommand.h"
#include "Singleton.h"
/*
 * execute is creating new vars and enter them into symbol and sim maps.
 */

int DefineVarCommand :: execute(vector<string> &tokens, int curr_index) {
    Singleton* singleton = Singleton::getInstance();
    // if it's new var - enter it to symbol table and sim table
    if(tokens[curr_index + 2] == "=") {
        Var* var = new Var();
        singleton->insertToSymbolTable(tokens[curr_index + 1] ,var);
        return 1;
    }

    Var* var;
    // take out the quotation marks from the sim name
    string sim_name = tokens[curr_index + 4].substr(1, tokens[curr_index + 4].length() - 2);
    var = singleton->getSimTable()[sim_name];
    var->setDirection(tokens[curr_index + 2]);
    var->setSimName(tokens[curr_index + 4]);
    // update var in symbol table and sim table
    singleton->insertToSymbolTable(tokens[curr_index + 1], var);
    singleton->insertToSimTable(tokens[curr_index + 4], var);
    return 5;
}