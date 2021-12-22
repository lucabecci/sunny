#include <bits/stdc++.h>
#include <netinet/in.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

class client
{
  private:
    char buff[MAX];
    int n;
    void process(int sockfd);
  public:
    int connection(void);
};

int client::connection(void)
{
  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1)
  {
    std::cout << "Socket creation failed" << std::endl;
    exit(0);
  }
  else 
    std::cout << "Socket successfuly created" << std::endl;
  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);

  if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0)
  {
    std::cout << "Connection with the TCP server failed" << std::endl;
    exit(0);
  }
  else
    std::cout << "Connected to the TCP server" << std::endl;
  process(sockfd);
  close(sockfd);
}

void client::process(int sockfd)
{
  for(;;)
  {
    bzero(buff, sizeof(buff));
    std::cout << "Enter str" << std::endl;
    n = 0;
    while((buff[n++] = getchar()) != '\n');

    write(sockfd, buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    std::cout << "Received from server" << buff << std::endl;
    if((strncmp(buff, "exit", 4)) == 0)
    {
      std::cout << "Client exit..." << std::endl;
      break;
    }
  }
}
