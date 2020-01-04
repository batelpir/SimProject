//
// Created by batel on 22/12/2019.
//
#include "OpenDataServerCommand.h"

/*
* read data from the client and update it in sim map.
*/
 void OpenDataServerCommand::openServer(int client_socket) {
    Singleton* singleton = Singleton::getInstance();
    mutex mutex_lock;

    char buffer[1024] = {0};
    while(!singleton->getIsDone()) {
        //reading from client
        int valread = read(client_socket, buffer, 1024);
        string buff_string(buffer);
        istringstream items(buff_string);
        string item;
        int count = 0;
        while (getline(items, item, ',')) {
            Var* var = singleton->getfromSimTable(singleton->getFromIndexTable(count));
            // update new value only if simulator affects
            if(var->getDirection() == "" || var->getDirection() =="<-") {
              mutex_lock.lock();
              var->setValue(stod(item));
              mutex_lock.unlock();
            }
            count++;
        }
        if (singleton->getIsDone()) {
            close(client_socket);
        }
    }
}
/*
 * open a socket and close it after a client connect with us.
 * create a thread and run the 'open server' function
 */
int OpenDataServerCommand::execute(vector<string> &tokens, int curr_index) {
    Singleton* singleton = Singleton::getInstance();
    this->port = Functions::shuntingYard(tokens[curr_index + 1]);
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
    if(client_socket == -1) {
        cout<<"Couldn't accept a client"<<endl;
    }
    close(socketfd);

    thread *recieveData = new thread(&OpenDataServerCommand::openServer, this, client_socket);
    // add the thread to the threads vector that in singleton.
    singleton->setToTreads(recieveData);
    return 2;
}