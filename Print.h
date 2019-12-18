//
// Created by shaked on 18/12/2019.
//

#ifndef EX3_PRINT_H
#define EX3_PRINT_H

#include <iostream>

using namespace std;
class Print : public Command {
public:
    virtual int execute(vector<string> tokens, int curr_index);
};


#endif //EX3_PRINT_H
