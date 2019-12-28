//
// Created by batel on 22/12/2019.
//
#include "OpenDataServerCommand.h"

void OpenDataServerCommand::openServer() {
    Singleton* singleton = Singleton::getInstance();
    mutex mutex_lock;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1) {
        cout<< "couldn't create a socket"<<endl;
        throw "Error";
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(this->port);
    if (bind(socketfd,(struct sockaddr*)&address, sizeof(address)) == -1) {
        cout<<"Couldn't bind a socket"<<endl;
        throw "Error";
    }
    if(listen(socketfd, 1) == -1) {
        cout<<"Couldn't listen to socket"<<endl;
        throw "Error";
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    //accepting a client.
    socklen_t addrlen = sizeof(address);
    int client_socket = accept(socketfd, (struct sockaddr *) &address, &addrlen);
    cout<<client_socket;
    if(client_socket == -1) {
        cout<<"Couldn't accept a client"<<endl;
    }
    close(socketfd);

    char buffer[1024] = {0};
    map<string, Var*> ::iterator iter = singleton->getSimTable().begin();
    while(true) {
        //reading from client
        int valread = read(client_socket, buffer, 1024);
        string buff_string(buffer);
        istringstream items(buff_string);
        string item;
        auto iter = singleton->getSimTable().begin();
        //map<string, Var*> ::iterator iter = singleton->getSimTable().begin();
        cout<<buffer;
        while (getline(items, item, ',')) {
            mutex_lock.lock();
            // update new value only if simulator affects
            if (iter->second->getDirection() == "<-") {
                iter->second->setValue(stod(item));
            }
            mutex_lock.unlock();
            iter++;
        }
    }
}
int OpenDataServerCommand::execute(vector<string> tokens, int curr_index) {
    Singleton* singleton = Singleton::getInstance();
    this->port = stoi(tokens[curr_index]);
    thread *recieveData = new thread(&OpenDataServerCommand::openServer, this);
    singleton->getThreads().push_back(recieveData);
    return (curr_index + 2);
}