#include <bits/stdc++.h>
#include <cstring>

enum CASES {
    HELP = 0,
};
class desition
{
    private:
        void help(void);
        void memory(std::string command);
    public:
        void cmd(std::string command);
};


void desition::cmd(std::string command)
{
    if(command == "help"){
        help();
    }else{
        memory(command);
    }
    return;
}

void desition::memory(std::string command)
{
    
}

void desition::help(void)
{
    std::cout << "- memory" << std::endl;
    std::cout << "- dms" << std::endl;
    std::cout << "- clear cache" << std::endl;
    return;
}
