//
// Created by batel on 02/01/2020.
//

#ifndef EX3__SEPARATESCOPECOMM_H_
#define EX3__SEPARATESCOPECOMM_H_
#include <vector>
#include <string>
/*
 * has behaviors that all of the commands which
 * have separate privet scope should have.
 */
using namespace std;
class SeparateScopeComm {
 public:
  vector<string> makeSubTokens(vector<string> tokens, int index_of_begin);
};
#endif //EX3__SEPARATESCOPECOMM_H_
