//
// Created by shaked on 23/12/2019.
//

#include "ConnectControlClientCommand.h"

/*
 * trying to connect as client to the server.
 * the server is the simulator.
 */
void ConnectControlClientCommand::connectClient(int client_socket) {
    // flag that checks whether we finished reading the file
    bool is_done = false;
    Singleton* singleton = Singleton::getInstance();
    list<string> *strings_to_sim = singleton->getStringsToSim();
    // send data to the server as long as there is a data to send
    // and as long as the file isn't over.
    while (!strings_to_sim->empty() || !is_done) {
        if (!strings_to_sim->empty()) {
            string str = strings_to_sim->front();
            strings_to_sim->pop_front();
            // the case that the file is reached to his last line.
            if (str.find("done") != -1) {
                is_done = true;
                singleton->setIsDone();
            } else { // sending the data
                string msg = "set ";
                msg.append(str);
                msg.append("\r\n");
                char h[msg.length() + 1];
                strcpy(h, msg.c_str());
                int is_sent = send(client_socket, h, strlen(h), 0);
                if (is_sent == -1) {
                    cout << "Couldn't send data to server"<<endl;
                }
            }
        }
    }
    close(client_socket);
}
/*
 * Connect client to server and open thread for sending data
 */
int ConnectControlClientCommand::execute(vector<string> &tokens, int curr_index) {
    Singleton* singleton = Singleton::getInstance();
    // set ip's and port's value.
    this->ip = tokens[curr_index + 1].substr(1, tokens[curr_index + 1].length() - 2);
    this->port = Functions::shuntingYard(tokens[curr_index + 2]);
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1) {
        cout << "Couldn't open client socket"<<endl;
        throw "Error";
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(this->ip.c_str());
    //address.sin_addr.s_addr = inet_addr("10.0.2.2");
    address.sin_port = htons(this->port);
    int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
    if (is_connect == -1) {
        cout <<"Couldn't connect to server"<<endl;
        throw "Error";
    }
    thread *sendData = new thread(&ConnectControlClientCommand::connectClient, this, client_socket);
    // add the thread to the threads vector that in singleton.
    singleton->setToTreads(sendData);
    return 3;
}
