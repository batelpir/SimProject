//
// Created by shaked on 18/12/2019.
//

#include "Sleep.h"
Sleep::Sleep(vector<string> tokens_input) {
  this->tokens = tokens_input;
}

int Sleep::execute(int curr_index) {
  // convert string to number - atoi doesn't convert to float numbers
  stringstream sleep_string(tokens[curr_index + 1]);
  float sleep_time = 0;
  sleep_string >> sleep_time;
  // sleep takes arguments in seconds therefore converting to seconds is neededed
  sleep(sleep_time / 1000);
  return curr_index + 2;
}