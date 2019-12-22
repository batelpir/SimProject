//
// Created by shaked on 18/12/2019.
//

#include "Sleep.h"

int Sleep::execute(vector<string> tokens, int curr_index) {
    //call shunting yard to check if it's a number or not
    //if it's a number - execute this
    // convert string to number - atoi doesn't convert to float numbers
    stringstream sleep_string(tokens[curr_index + 1]);
    float sleep_time = 0;
    sleep_string >> sleep_time;
    // sleep takes arguments in seconds therefore converting to seconds is neededed
    sleep(sleep_time / 1000);
    // else
    // call shunting yard
    return curr_index + 2;

}