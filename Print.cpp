//
// Created by shaked on 18/12/2019.
//

#include "Print.h"

int Print :: execute(vector<string> tokens, int curr_index) {
    this->string_to_print = tokens[curr_index + 1];
    // only if brackets contain double quote
    if (string_to_print.find("\"")) {
        cout <<this->string_to_print<<endl;
    } else {
        // call shunting yard and check if it's an expression or not
        //int res = shunting_yard;
        //cout <<res<<endl;
    }
    if (this->string_to_print == "done") {
        Singleton* singleton = Singleton::getInstance();
        //singleton->insertStringsToSim("done");
    }
    return curr_index + 2;
}