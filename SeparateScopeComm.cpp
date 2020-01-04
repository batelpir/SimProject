//
// Created by batel on 02/01/2020.
//
#include "SeparateScopeComm.h"

//index_begin is the index of the first string after '{'
vector<string> SeparateScopeComm::makeSubTokens(vector<string> tokens, int index_of_begin) {
  vector<string> sub_tokens;
  // count sub scopes
  int counter = 0;
  int index_end = index_of_begin;
  while (tokens[index_end] != "}" || counter != 0) {
    if (tokens[index_end] == "{") {
      counter ++;
    }
    if(tokens[index_end] == "}") {
      counter --;
    }
    sub_tokens.push_back(tokens[index_end]);
    index_end++;
  } // now index of end is the index of "}" and sub tokens is done.
  return sub_tokens;
}
