//
// Created by shaked on 23/12/2019.
//

#ifndef EX3_CONNECTCONTROLCLIENTCOMMAND_H
#define EX3_CONNECTCONTROLCLIENTCOMMAND_H

#include "Singleton.h"
#include "Command.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class ConnectControlClientCommand : public Command {
    string ip;
    int port;
public:
    virtual int execute(vector<string> tokens, int curr_index);
    void connectClient(vector<string> tokens, int curr_index);
};


#endif //EX3_CONNECTCONTROLCLIENTCOMMAND_H
