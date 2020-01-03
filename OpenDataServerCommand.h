//
// Created by batel on 22/12/2019.
//

#ifndef EX3__OPENDATASERVERCOMMAND_H_
#define EX3__OPENDATASERVERCOMMAND_H_
#include "Singleton.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <sstream>
#include <thread>
#include <stdlib.h> // atoi
#include <mutex>

using namespace std;
/*
 * we are acting here as a server and the client is only the simulator.
 */
class OpenDataServerCommand : public Command {
int port;
 public:
    virtual int execute(vector<string> &tokens, int curr_index);
    void openServer();
};
#endif //EX3__OPENDATASERVERCOMMAND_H_
