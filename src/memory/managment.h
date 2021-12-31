#include<cstring>
#include <netinet/in.h>
#include <unistd.h>

extern int sockfd;
class managment
{
  private:
    void send(void);
    bool pst(std::string f);
    std::string first(std::string str);
  public:
    void validate(std::string command);
    void execute(std::string command);
};
void managment::validate(std::string command)
{
  std::cout << sockfd << std::endl;
  std::string initial = first(command);
  if(initial == "put")
  {
    std::cout << "put command" << std::endl;
    pst(command);
  }
  else if(initial == "remove")
  {
    std::cout << "remove command" << std::endl;
  }
  else if(initial == "get")
  {
    std::cout << "get command" << std::endl;
  }
  else std::cout << "invalid command" << std::endl;
  return;
}

bool managment::pst(std::string f)
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
