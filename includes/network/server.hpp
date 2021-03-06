#ifndef SERVER_H
#define SERVER_H

#include "../interface/server_decisions.hpp"

extern int connfd;

#define PORT 8080
#define MAX_SV 1024
#define SA struct sockaddr

class server
{
  private:
    server_decisions sd;
    char buff[MAX_SV];
    int n;
    int internal_sockfd;
  public:
    void connection(void);
    bool process();
};

#endif