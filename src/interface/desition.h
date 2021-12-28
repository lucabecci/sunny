#include <bits/stdc++.h>
#include <cstring>

enum CASES {
    HELP = 0,
};
class desition
{
    private:
        void help(void);
    public:
        void cmd(std::string command);
};


void desition::cmd(std::string command)
{
    if(command == "help"){
        help();
    }else{
        std::cout << "Invalid command" << std::endl;
    }
    return;
}


void desition::help(void)
{
    std::cout << "- memory" << std::endl;
    std::cout << "- dms" << std::endl;
    std::cout << "- clear cache" << std::endl;
    return;
}
