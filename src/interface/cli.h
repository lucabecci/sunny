#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include "./colors.h"

extern bool logs;

class cli
{
    private:
        std::string lowercase(std::string str);
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

        str = lowercase(str);
        if(str == "exit")
        {
            break;
        }
        else std::cout << "Word input: " << str << std::endl;
    }
    std::cout << "CLI FINISHED" << std::endl;
    return;
}


