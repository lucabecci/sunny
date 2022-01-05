#include <algorithm>
#include <cstring>
#include <iostream>
#include "./client_decisions.h"

class cli
{
    private:
        int sock;
        std::string lowercase(std::string str);
        void name(void);
        client_decisions d;
    public:
        cli(void);
        int run(void);        
};
cli::cli()
{
    name();
}

std::string cli::lowercase(std::string str)
{
    std::for_each(str.begin(), str.end(), [](char & c)
    {
        c = ::tolower(c);
    });
    return str;
}

void cli::name(void)
{
    d.__stdoutp(" ░██████╗██╗░░░██╗███╗░░██╗███╗░░██╗██╗░░░██╗", "ERROR");
    d.__stdoutp(" ██╔════╝██║░░░██║████╗░██║████╗░██║╚██╗░██╔╝", "WARNING");
    d.__stdoutp(" ╚█████╗░██║░░░██║██╔██╗██║██╔██╗██║░╚████╔╝░", "SUCCESS");
    d.__stdoutp(" ░╚═══██╗██║░░░██║██║╚████║██║╚████║░░╚██╔╝░░", "INFO");
    d.__stdoutp(" ██████╔╝╚██████╔╝██║░╚███║██║░╚███║░░░██║░░░", "MAGENTA");
    d.__stdoutp(" ╚═════╝░░╚═════╝░╚═╝░░╚══╝╚═╝░░╚══╝░░░╚═╝░░░", "CYAN");
    return;
}

int cli::run(void)
{
    char ch;
    std::string str = "";
    std::cout << "Sunny => ";
    while (std::cin.get(ch) && ch != '\n')
        str += ch;
    if(str == "clear")
    {
        system("clear");
        name();
        return 0;
    }
    d.cmd(str);
    if(str == "exit")
    {
        return 1;
    }
    return 0;
}


