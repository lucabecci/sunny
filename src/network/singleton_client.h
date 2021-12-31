#include <mutex>
#include <netinet/in.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "../interface/cli.h"

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

class singleton_client
{
  private:    
    singleton_client(){};
    singleton_client(singleton_client const&) {};
    singleton_client& operator=(singleton_client const&) {return *this;};
    static singleton_client * instance_;
    void process(void);
  public:
    int sockfd;
    static singleton_client * instance();
    void connection(void);
    bool pst(std::string c);
};

singleton_client* singleton_client::instance_ = NULL;

singleton_client* singleton_client::instance()
{
  if(!instance_) instance_ = new singleton_client();
  return instance_; 
}

bool singleton_client::pst(std::string f)
{
  char buff[f.length()];
  for(std::string::size_type i = 0; i < f.size(); ++i) {
    buff[i] = f[i];
  }
  std::cout << buff << std::endl;
  if(sockfd < 1)
  {
    std::cout << "Socket not created" << std::endl;
    return false;
  }
  write(sockfd, buff, sizeof(buff));
  bzero(buff, sizeof(buff));
  return true;
}

void singleton_client::connection(void)
{
  int connfd;
  struct sockaddr_in servaddr;
  
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
}

void singleton_client::process(void)
{

}
