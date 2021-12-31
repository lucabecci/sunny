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

#define PORT 8080
#define MAX 80
#define SA struct sockaddr

class server
{
  private:
    char buff[MAX];
    void process(int connfd);
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
    bzero(&servaddr, sizeof(servaddr)); //limpiando bits en memoria

    //declarando y asignando las variables de network
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    
    //Comprobacion para el bind del socket
    if((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0)
    {
      std::cout << "Socket bind failed" << std::endl;
      exit(0);
    }
    else std::cout << "Socket successfully binded" << std::endl;

    //Comprobacion para saber si el socket esta escuchando en el puerto especificado
    if((listen(sockfd, 5)) != 0)
    {
      std::cout << "Server listen failed" << std::endl;
      exit(0);
    }
    else std::cout << "Server listen" << std::endl;
    
    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len);
    
    //Comprobacion para ver si el socket acepto la conexion del cliente TCP
    if(connfd < 0) std::cout << "Server accept failed" << std::endl;
    else std::cout << "Server accept the client" << std::endl;
    process(connfd);
    close(sockfd);
    return 0;
  }
}

void server::process(int connfd)
{
  //for infinito para recibir los buffer-msg del cliente TCP
  for(;;)
  {
    bzero(buff, MAX);
    read(connfd, buff, sizeof(buff));
    //Stdout del buffer recibido
    std::cout << "Message received from client: " << buff << std::endl;
    bzero(buff, MAX);
  }
}


#endif
