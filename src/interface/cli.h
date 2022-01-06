#include <algorithm>
#include <cstring>
#include <iostream>
#include "./client_decisions.h"

class cli
{
    private:
        int sock;
        void initial_information(void);
        void name(void);
        client_decisions d;
    public:
        cli(void);
        int run(void);        
};
cli::cli()
{
    name();
    initial_information();
}

void cli::initial_information(void)
{
    d.__stdoutp("   FREE AND OPEN SOURCE IN MEMORY DATABASE", "NOT_BOLD_NORMAL");
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
        initial_information();
        return 0;
    }
    d.cmd(str);
    if(str == "exit")
    {
        return 1;
    }
    return 0;
}


