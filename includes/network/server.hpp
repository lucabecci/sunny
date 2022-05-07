#ifndef SERVER_H
#define SERVER_H

extern int connfd;

#define PORT 8080
#define MAX 1024
#define SA struct sockaddr

class server
{
  private:
    server_decisions sd;
    char buff[MAX];
    int n;
    int internal_sockfd;
  public:
    void connection(void);
    bool process();
};

#endif