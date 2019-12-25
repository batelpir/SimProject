// Headers files
/*
#include "Parser.h"
#include "Command.h"
#include "UpdatingCommand.h"
#include <string>
#include <vector>
#include <thread>
*/

#include "Singleton.h"
#include "Command.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>




using namespace std;


int main(int argc, char *argv[]) {
    vector<string> tokens;
     /*
    if  (argc == 2) {
        //lexer(argv[1]);
    } else {
        cout << "File name is not supplied\n";
    }*/
    // use parser with try & catch!!!
    Singleton* singleton = Singleton::getInstance();
    //tokens = Functions::lexer("flyCopy.txt");

    /*
    vector<thread> threads = singleton->getThreads();
    for(auto &thread : threads) {
        thread.join();
    }*/

    //new Parser(tokens);

    /*
    // flag that checks whether we finished reading the file
    bool is_done = false;
    Singleton *singleton = Singleton::getInstance();
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        cout << "error";
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    string ip = "10.0.2.2";
    address.sin_addr.s_addr = inet_addr(ip.c_str());
    int port = 5402;
    address.sin_port = htons(port);

    int is_connect = connect(client_socket, (struct sockaddr *) &address, sizeof(address));
    if (is_connect == -1) {
        cout << "error";
    }
    cout <<is_connect;
    while(true) {
        const char h[] = "set controls/flight/rudder 1\r\n";
        const char h1[] = "set controls/flight/rudder -1\r\n";
        //list<string> strings_to_sim = singleton->getStringsToSim();
        if(is_connect != -1) {
            //string msg = "set /controls/flight/rudder 1";
            int is_sent = send(client_socket, h, strlen(h), 0);
            sleep(15);
            //msg = "set /controls/flight/rudder -1";
            is_sent = send(client_socket, h1, strlen(h1), 0);
            sleep(15);
        }
    }
     */

    mutex mutex_lock;
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd == -1) {
        cout<< "couldn't create a socket"<<endl;
        throw "Error";
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5400);
    if (bind(socketfd,(struct sockaddr*)&address, sizeof(address)) == -1) {
        cout<<"Couldn't bind a socket"<<endl;
        throw "Error";
    }
    if(listen(socketfd, 1) == -1) {
        cout<<"Couldn't listen to socket"<<endl;
        throw "Error";
    }
    //accepting a client.
    int addrlen = sizeof(address);
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
    cout<<client_socket;
    if(client_socket == -1) {
        cout<<"Couldn't accept a client"<<endl;
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
            cout <<line;
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





    return 0;
}