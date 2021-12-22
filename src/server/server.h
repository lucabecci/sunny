#include <bits/stdc++.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<unistd.h>
#include <netdb.h>
#include <cstring>

#define PORT 8080
#define MAX 80
#define SA struct sockaddr

class server
{
  private:
    char buff[MAX];
    int n;
    void process(int connfd);
  public:
    void connect(void);
};




