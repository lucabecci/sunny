#include<vector>
#include<cstring>
#include "../../includes/interface/server_decisions.hpp"
#include "../structure/querys.cpp"


std::vector<std::string> threeSplit(std::string command)
{
    int count = 0;
    int loop = 0;
    std::vector<std::string> v;
    std::string word = "";
    for(std::string::size_type i = 0; i < command.size(); ++i) {
        count++;
        if(command[i] == ' ' && loop < 2)
        {
            v.push_back(word);  
            word = "";
            loop++;
        }
        else word += command[i];
        if(count == command.size()){
            v.push_back(word);
        }
    }
    return v;
}

void server_decisions::pst(std::string msg)
{
    for(std::string::size_type i = 0; i < msg.size(); ++i) {
        buff[i] = msg[i];
    }
    if(connfd < 1)
    {
        std::cout << "Socket without connections" << std::endl;
        return;
    }
    write(connfd, buff, sizeof(buff));
    bzero(buff, sizeof(buff));
    return;
}

void server_decisions::analyze(std::string command)
{
    std::vector<std::string> three_v = threeSplit(command + " ");
    if(three_v[0] == "put")
    {   
        q.put(three_v[1], three_v[2]);
    }
    else if(three_v[0] == "get")
    {
        std::string value = q.get(three_v[1]);
        if(value == "NULL_V_SUNNY") pst("Value not found");
        else pst(value);
    }
    return;
}