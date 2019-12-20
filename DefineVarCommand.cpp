//
// Created by shaked on 20/12/2019.
//

#include "DefineVarCommand.h"
//#include "Singleton.h"

DefineVarCommand::DefineVarCommand(vector<string> tokens_input) {
    this->tokens = tokens_input;
}
int DefineVarCommand :: execute(int curr_index) {
    // if it's new var
    if (tokens[curr_index] == "var") {
        Var *var = new Var();
        var->setArrow(tokens[curr_index + 2]);
        var->setSimName(tokens[curr_index + 4]);
        intstance->setSymbolTable(tokens[curr_index], var);
        intstance->setSimTable(tokens[curr_index + 4], var);
        return curr_index + 5;
    } else {
        // it means it's not a new var,
        // here supposed to be the code from ex 1
        return curr_index + 3;
    }

}