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
#include <thread>
/*
 * the command which makes as to connect to the simulator as client.
 * "execute" is calling to "connect client"
 */
class ConnectControlClientCommand : public Command {
  string ip;
  int port;
public:
  virtual int execute(vector<string> &tokens, int curr_index);
  void connectClient();
};


#endif //EX3_CONNECTCONTROLCLIENTCOMMAND_H
