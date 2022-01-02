#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include "../interface/server_decisions.h"
#define PORT 8080
#define MAX 80
#define SA struct sockaddr

class server
{
  private:
    server_decisions sd;
    char buff[MAX];
    int n;
    bool process(int connfd);
  public:
    int connection(void);
};

int server::connection(void)
{
  //Declaracion de variables
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;
  //Se instancia el socket a usar
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  //Comprobando si el socket fue creado
  if(sockfd == -1)
  {
    std::cout << "Socket creation failed..." << std::endl;
    exit(0);
  }
  else
  {
    std::cout << "Socket successfully connected..." << std::endl;
    bzero(&servaddr, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
    {
      std::cout << "Socket bind failed" << std::endl;
      exit(0);
    }
    else std::cout << "Socket successfully binded" << std::endl;

    if((listen(sockfd, 5)) != 0)
    {
      std::cout << "Server listen failed" << std::endl;
      exit(0);
    }
    else std::cout << "Server listen" << std::endl;
    
    for(;;)
    {
      len = sizeof(cli);
      connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);
      std::cout << connfd << std::endl;
      if(connfd < 0) std::cout << "Server accept failed" << std::endl;
      else std::cout << "Server accept the client" << std::endl;
      bool exit = process(connfd);
      if(exit){
        break;
      }
      connfd = 0;
    }
    
    close(sockfd);
    return 0;
  }
}

bool server::process(int connfd)
{
  bool exit = false;
  for(;;)
  {
    bzero(buff, MAX);
    read(connfd, buff, sizeof(buff));
    std::string bstr = buff;
    if(bstr.length() > 1)
    {
      std::cout << "Message received from client: " << buff << std::endl;
      if(bstr == "disconnect"){
        bzero(buff, MAX);
        exit = true;
        break;
      }
      if(bstr == "exit"){
        bzero(buff, MAX);
        exit = true;
        break;
      }
      sd.analyze(bstr);
      n = 0;
    }else{
      break;
    }
  }
  return exit;
}


#endif
