#include<cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "../../includes/memory/managment.hpp"

std::string managment::validate(std::string command)
{
  std::string initial = first(command);
  std::string pstcall = "";
  if(initial == "put")
  {
    pstcall = pst(command, false);
  }
  else if(initial == "get")
  {
    pstcall = pst(command, true);
  }
  else pstcall = "Invalid command";
  return pstcall;
}

std::string managment::pst(std::string f, bool capture)
{
  for(std::string::size_type i = 0; i < f.size(); ++i) {
    buff[i] = f[i];
  }
  if(sockfd < 1) return "Socket not created";
  write(sockfd, buff, sizeof(buff));
  bzero(buff, sizeof(buff));
  if(capture)
  {
    read(sockfd, buff, sizeof(buff));
    std::string message;
    message = buff;
    bzero(buff, sizeof(buff));
    return message;
  }else
  {
    bzero(buff, sizeof(buff));
    return "";
  }
}

std::string managment::first(std::string str)
{
  std::string word = "";
  for(std::string::size_type i = 0; i < str.size(); ++i)
  {
    if(str[i] == ' ')
    {
      break;
    }
    else
    {
      word += str[i];
    }
  }
  return word;
}
