#include<cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#define MAX 1024

extern int sockfd;
class managment
{
  private:
    std::string first(std::string str);
    char buff[1024];
  public:
    std::string pst(std::string f);
    std::string validate(std::string command);
};
std::string managment::validate(std::string command)
{
  std::string initial = first(command);
  std::string pstcall = "";
  if(initial == "put")
  {
    pstcall = pst(command);
  }
  else if(initial == "remove")
  {
    pstcall = pst(command);
  }
  else if(initial == "get")
  {
    pstcall = pst(command);
  }
  else pstcall = "Invalid command";
  return pstcall;
}

std::string managment::pst(std::string f)
{
  for(std::string::size_type i = 0; i < f.size(); ++i) {
    buff[i] = f[i];
  }
  if(sockfd < 1) return "Socket not created";
  write(sockfd, buff, sizeof(buff));
  bzero(buff, sizeof(buff));
  read(sockfd, buff, sizeof(buff));
  std::string message;
  message = buff;
  bzero(buff, sizeof(buff));
  return message;
}

std::string managment::first(std::string str)
{
  std::string word = "";
  for(auto x : str)
  {
    if(x == ' ')
    {
      break;
    }
    else
    {
      word += x;
    }
  }
  return word;
}
