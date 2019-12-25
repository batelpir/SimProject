//
// Created by shaked on 23/12/2019.
//

#include "ConnectControlClientCommand.h"

void ConnectControlClientCommand::connectClient(vector<string> tokens, int curr_index) {
    // flag that checks whether we finished reading the file
    bool is_done = false;
    Singleton* singleton = Singleton::getInstance();
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if( client_socket == -1) {
        cout << "error";
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(this->ip.c_str());
    address.sin_port = htons(this->port);
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        cout <<"error";
    }
    list<string> strings_to_sim = singleton->getStringsToSim();

    while (!strings_to_sim.empty() || !is_done) {
        if (!strings_to_sim.empty()) {
            string str = strings_to_sim.front();
            strings_to_sim.pop_front();
            if (str == "done") {
                is_done = true;
            } else {
                string msg = "set ";
                msg.append(str);
                int is_sent = send(client_socket, msg.c_str(), msg.length(), 0);
                if (is_sent == -1) {
                    cout << "error";
                }
            }
        }

    }
}
int ConnectControlClientCommand::execute(vector<string> tokens, int curr_index) {
    Singleton* singleton = Singleton::getInstance();
    this->ip = tokens[curr_index + 1];
    this->port = stoi(tokens[curr_index + 2]);
    thread* t = singleton->getClientThread();
    //t = new thread(connectClient(tokens, curr_index));
    //singleton->getClientThread(connectClient(tokens, curr_index));
    //singleton->addThread(connectClientThread);
    return (curr_index + 3);
}
