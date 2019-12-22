//
// Created by batel on 22/12/2019.
//
#include "openDataServerCommand.h"
int openDataServerCommand::execute(vector<string> tokens, int curr_index) {
  Singleton* singleton = Singleton::getInstance();

  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if(socketfd == -1) {
    cout<< "couldn't create a socket"<<endl;
    return -1;
  }
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd,(struct sockaddr*)&address, sizeof(address) == -1)) {
    cout<<"error"<< endl;
    return -2;
  }
  if(listen(socketfd, 1) == -1) {
    cout<<"error"<<endl;
    return -3;
  }
  //accepting a client.
  int client_socket = accept(socketfd, (struct sockaddr*) &address, (socklen_t*)&address);
  if(client_socket == -1) {
    cout<<"error"<<endl;
    return -4;
  }

  // close(socketfd);

  //reading from client
  char buffer[1024] = {0};
  int valread = read( client_socket , buffer, 1024);
  string buff_string(buffer);
  istringstream lines(buff_string);
  string line;
  auto iter = singleton->getSimTable().begin();
  while(getline(lines,line, '\n')) {
    string item;
    istringstream line_stream(line);
    while(getline(line_stream,item,',')) {
      iter->second->setValue(stod(item));
      iter++;
    }
  }

  //writing back to client
  char *hello = "Hello, I can hear you! \n";
  send(client_socket , hello , strlen(hello) , 0 );
  std::cout<<"Hello message sent\n"<<std::endl;

}