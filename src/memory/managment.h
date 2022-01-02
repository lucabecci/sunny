#include<cstring>
#include <netinet/in.h>
#include <unistd.h>

#define MAX 1024

extern int sockfd;
class managment
{
  private:
    std::string first(std::string str);
  public:
    void pst(std::string f);
    void validate(std::string command);
};
void managment::validate(std::string command)
{
  std::string initial = first(command);
  if(initial == "put")
  {
    pst(command);
  }
  else if(initial == "remove")
  {
    pst(command);
  }
  else if(initial == "get")
  {
    pst(command);
  }
  else std::cout << "Invalid command" << std::endl;
  return;
}

void managment::pst(std::string f)
{
  char buff[MAX];
  for(std::string::size_type i = 0; i < f.size(); ++i) {
    buff[i] = f[i];
  }
  if(sockfd < 1)
  {
    std::cout << "Socket not created" << std::endl;
    return;
  }
  write(sockfd, buff, sizeof(buff));
  bzero(buff, sizeof(buff));
  std::cout << "Receiving: " << std::endl;
  std::cout << "----" << sockfd << std::endl;
  std::cout << "----" << buff << std::endl;
  std::cout << "----" << sizeof(buff) << std::endl;
  read(sockfd, buff, sizeof(buff));
  std::cout << buff << std::endl;
  return;
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
