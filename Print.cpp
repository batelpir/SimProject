//
// Created by shaked on 18/12/2019.
//

#include "Print.h"

int Print :: execute(vector<string> &tokens, int curr_index) {
    string string_to_print = tokens[curr_index + 1];
    // only if brackets contain double quote
    if (string_to_print.find("\"\"")) {
        cout <<string_to_print.substr(1,string_to_print.length() - 2)<<endl;
    } else {
        // call shunting yard and calculate the expression
        double val = Functions::shuntingYard(string_to_print);
        cout<<val<<endl;
    }
    if (string_to_print == "done") {
        Singleton* singleton = Singleton::getInstance();
        singleton->insertStringsToSim("done");
    }
    return curr_index + 2;
}