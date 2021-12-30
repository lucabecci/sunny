#include<bits/stdc++.h>
#include<cstring>

enum options
{
  invalid,

};


class managment
{
  private:
    void send(void);
    options resolveOpt(std::string command);
  public:
    void validate(std::string command);
    void execute(std::string command);
};

void managment::validate(std::string command)
{
  switch(resolveOpt(command))
  {
    case invalid:
      std::cout << "Invalid command" << std::endl;
    default:
      std::cout << "Other command" << std::endl;
  }
  return;
}


options managment::resolveOpt(std::string command)
{
  if(command == "test") return invalid;
}
