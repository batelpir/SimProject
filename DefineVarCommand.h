//
// Created by shaked on 20/12/2019.
//

#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H


class DefineVarCommand : public Command {
    vector<string> tokens;
public:
    DefineVarCommand(vector<string> tokens_input);
    virtual int execute(int curr_index);
};


#endif //EX3_DEFINEVARCOMMAND_H
