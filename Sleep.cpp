//
// Created by shaked on 18/12/2019.
//

#include "Sleep.h"

int Sleep::execute(vector<string> &tokens, int curr_index) {
    string sleep_string(tokens[curr_index + 1]);
    double sleep_time = Functions::shuntingYard(sleep_string);
    chrono::milliseconds duration((int)sleep_time);
    this_thread::sleep_for(duration);
    return 2;

}