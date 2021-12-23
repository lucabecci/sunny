#include <bits/stdc++.h>
#include <cstring>
#include "./colors.h"

extern bool logs;

class cli
{
    private:
        void sun(void);
        void name(void);
        colors c;
    public:
        cli(void);
        void run(void);        
};
cli::cli(void)
{
    name();
}

void cli::name(void)
{
    std::cout << logs << std::endl;
    std::cout << " ░██████╗██╗░░░██╗███╗░░██╗███╗░░██╗██╗░░░██╗" << std::endl;
    std::cout << " ██╔════╝██║░░░██║████╗░██║████╗░██║╚██╗░██╔╝" << std::endl;
    std::cout << " ╚█████╗░██║░░░██║██╔██╗██║██╔██╗██║░╚████╔╝░" << std::endl;
    std::cout << " ░╚═══██╗██║░░░██║██║╚████║██║╚████║░░╚██╔╝░░" << std::endl;
    std::cout << " ██████╔╝╚██████╔╝██║░╚███║██║░╚███║░░░██║░░░" << std::endl;
    std::cout << " ╚═════╝░░╚═════╝░╚═╝░░╚══╝╚═╝░░╚══╝░░░╚═╝░░░" << std::endl;
    return;
}

void cli::run(void)
{
    while(1)
    {
        char ch;
        std::string str = "";
        std::cout << c.change(0) << "Sunny => ";
        while (std::cin.get(ch) && ch != '\n')
            str += ch;
        if(str == "exit")
        {
            break;
        }
        else std::cout << "Word input: " << str << std::endl;
    }
    std::cout << "CLI FINISHED" << std::endl;
    return;
}


