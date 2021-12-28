#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include "../utils/colors.h"
#include "./desition.h"
extern bool logs;

class cli
{
    private:
        std::string lowercase(std::string str);
        void name(void);
        colors c;
        desition d;
    public:
        cli(void);
        int run(void);        
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

int cli::run(void)
{
    char ch;
    std::string str = "";
    std::cout << c.change(0) << "Sunny => ";
    while (std::cin.get(ch) && ch != '\n')
        str += ch;

    str = lowercase(str);
    std::string parsed = str;
    d.cmd(parsed);
    if(str == "exit")
    {
        return 1;
    }
    else std::cout << "Word input: " << str << std::endl;
    return 0;
}


