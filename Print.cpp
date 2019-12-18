//
// Created by shaked on 18/12/2019.
//

#include "Print.h"

int Print :: execute(vector<string> tokens, int curr_index) {
    cout <<tokens[curr_index + 1]<<endl;
    return curr_index + 2;
}