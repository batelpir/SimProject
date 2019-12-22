//
// Created by batel on 22/12/2019.
//

#ifndef EX3__OPENDATASERVERCOMMAND_H_
#define EX3__OPENDATASERVERCOMMAND_H_
#include "Command.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <netinet/in.h>
#include <sstream>
#include "Singleton.h"
using namespace std;

class openDataServerCommand : Command {
int port;
 public:
  virtual int execute(vector<string> tokens, int curr_index) = 0;
};
#endif //EX3__OPENDATASERVERCOMMAND_H_
