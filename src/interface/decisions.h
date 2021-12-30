#include <bits/stdc++.h>
#include <cstring>
#include "../memory/managment.h"

enum CASES {
    HELP = 0,
};
class decisions
{
    private:
        managment m;
        void help(void);
    public:
        void cmd(std::string command);
};


void decisions::cmd(std::string command)
{
    if(command == "help"){
        help();
    }else{
        m.validate(command);
    }
    return;
}

void decisions::help(void)
{
    std::cout << "- memory" << std::endl;
    std::cout << "- dms" << std::endl;
    std::cout << "- clear cache" << std::endl;
    return;
}
