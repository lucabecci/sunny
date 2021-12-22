#include <bits/stdc++.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<unistd.h>
#include <netdb.h>
#include <cstring>
#include "./server.h"
#define PORT 8080
#define MAX 80
#define SA struct sockaddr

void server::connect(void)
{
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
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
    
    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);

    if(connfd < 0) std::cout << "Server accept failed" << std::endl;
    else std::cout << "Server accept the client" << std::endl;
    process(connfd);
    close(sockfd);
  }
}

void server::process(int connfd)
{
  for(;;)
  {
    bzero(buff, MAX);
    read(connfd, buff, sizeof(buff));
    std::cout << "Message received from client: " << buff << std::endl;
    bzero(buff, MAX);
    n = 0;

    while((buff[n++] = getchar()) != '\n')
    {
      write(connfd, buff, sizeof(buff));

      if(strncmp("exit", buff, 4) == 0)
      {
        std::cout << "Server exit..." << std::endl;
        break;
      }
    }
  }
}