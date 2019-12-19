//
// Created by shaked on 18/12/2019.
//

#include "Print.h"

Print::Print(vector<string> tokens_input) {
  this->tokens = tokens_input;
}
int Print :: execute(int curr_index) {
    cout <<tokens[curr_index + 1]<<endl;
    return curr_index + 2;
}