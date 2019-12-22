//
// Created by shaked on 18/12/2019.
//

#include "Print.h"

int Print :: execute(vector<string> tokens, int curr_index) {
    // only if brackets contain double quote
    if (tokens[curr_index + 1].find("\"")) {
        cout <<tokens[curr_index + 1]<<endl;
    } else {
        // call shunting yard and check if it's an expression or not
        //int res = shunting_yard;
        //cout <<res<<endl;
    }
    return curr_index + 2;
}