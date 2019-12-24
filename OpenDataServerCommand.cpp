//
// Created by batel on 22/12/2019.
//
#include "OpenDataServerCommand.h"

void OpenDataServerCommand::openServer() {
    // ***** throw excepions ****
    Singleton* singleton = Singleton::getInstance();
    mutex mutex_lock;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1) {
        cout<< "couldn't create a socket"<<endl;
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(this->port);
    if (bind(socketfd,(struct sockaddr*)&address, sizeof(address) == -1)) {
        cout<<"error"<< endl;
    }
    if(listen(socketfd, 1) == -1) {
        cout<<"error"<<endl;
    }
    //accepting a client.
    int client_socket = accept(socketfd, (struct sockaddr*) &address, (socklen_t*)&address);
    if(client_socket == -1) {
        cout<<"error"<<endl;
    }

    close(socketfd);

    while(true) {
        //reading from client
        char buffer[1024] = {0};
        int valread = read(client_socket, buffer, 1024);
        string buff_string(buffer);
        istringstream lines(buff_string);
        string line;
        auto iter = singleton->getSimTable().begin();
        while (getline(lines, line, '\n')) {
            string item;
            istringstream line_stream(line);
            while (getline(line_stream, item, ',')) {
                // update var's value
                mutex_lock.lock();
                iter->second->setValue(stod(item));
                mutex_lock.unlock();
                iter++;
            }
        }
        sleep(0.001);
    }
}
int OpenDataServerCommand::execute(vector<string> tokens, int curr_index) {
    Singleton* singleton = Singleton::getInstance();
    this->port = stoi(tokens[curr_index]);
    //thread openServerThread(openServer());
    //singleton->addThread(openServerThread);
    return (curr_index + 2);
}