#pragma once

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include "../../includes/network/server.hpp"
#include "../interface/server_decisions.cpp"

void server::connection(void)
{
  struct sockaddr_in servaddr;
  internal_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(internal_sockfd == -1)
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

    if((bind(internal_sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
    {
      std::cout << "Socket bind failed" << std::endl;
      exit(0);
    }
    else std::cout << "Socket successfully binded" << std::endl;

    if((listen(internal_sockfd, 5)) != 0)
    {
      std::cout << "Server listen failed" << std::endl;
      exit(0);
    }
    else std::cout << "Server listen" << std::endl; 
  }
}

bool server::process()
{
  bool exit = false;
  for(;;)
  {
    int len;
    struct sockaddr_in cli;
    len = sizeof(cli);
    connfd = accept(internal_sockfd, (SA*)&cli, (socklen_t*)&len);
    if(connfd < 0) std::cout << "Server accept failed" << std::endl;
    for(;;)
    {
      bzero(buff, MAX);
      read(connfd, buff, sizeof(buff));
      std::string bstr = buff;
      if(bstr.length() > 1)
      {
        if(bstr == "disconnect"){
          bzero(buff, MAX);
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
    if(exit){
      break;
    }
    connfd = 0;
  }
  return 0;
}

