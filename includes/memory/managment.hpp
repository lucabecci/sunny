#ifndef MANAGMENT
#define MANAGMENT 

#define MAX 1024

extern int sockfd;
class managment
{
  private:
    std::string first(std::string str);
    char buff[MAX];
  public:
    std::string pst(std::string f, bool capture);
    std::string validate(std::string command);
};

#endif