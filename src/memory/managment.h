#include<bits/stdc++.h>
#include<cstring>

enum options
{
  put,
  del,
  g,
  notfound
};


class managment
{
  private:
    void send(void);
    std::string first(std::string str);
    options resolveOpt(std::string command);
  public:
    void validate(std::string command);
    void execute(std::string command);
};

void managment::validate(std::string command)
{

  std::string initial = first(command);
  std::cout << initial.length() << std::endl;
  switch(resolveOpt(initial))
  {
    case put:
      std::cout << "put" << command << std::endl;
    case del:
      std::cout << "remove" << command << std::endl;
    case g:
      std::cout << "get" << command << std::endl;
    case notfound:
      std::cout << "Invalid command" << std::endl;
  }
  return;
}


options managment::resolveOpt(std::string command)
{
  if(command == "put") return put;
  else if(command == "remove") return del;
  else if(command == "get") return g;
  else return notfound;
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
