#include<vector>
#include<cstring>
#include "../structure/querys.h"
class server_decisions
{
    private:
        std::vector<std::string> three_split(std::string command);
        querys q;
    public:
        void analyze(std::string command);
};

std::vector<std::string> threeSplit(std::string command)
{
    int loop = 0;
    std::vector<std::string> v;
    std::string word = "";
    for(auto x : command)
    {
        if(x == ' ' && loop < 3)
        {
            v.push_back(word);  
            word = "";
            loop++;
        }
        else word += x;
    }
    return v;
}

void server_decisions::analyze(std::string command)
{
    std::vector<std::string> three_v = threeSplit(command + " ");
    std::cout << three_v[0] << std::endl;
    if(three_v[0] == "put")
    {   
        q.put(three_v[1], three_v[2]);
    }
    else if(three_v[0] == "get")
    {
        std::string value = q.get(three_v[1]);
        std::cout << value << std::endl;
    }
    else if(three_v[0] == "remove")
    {
        q.remove(three_v[1]);
    }
    return;
}