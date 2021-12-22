#include <bits/stdc++.h>
#include <cstring>
class cli
{
    private:
        void select(int v);
    public:
        void run(void);        
};

void cli::run(void)
{
    while(1)
    {
        char ch;
        std::string str = "";
        std::cout << "Sunny => ";
        while (std::cin.get(ch) && ch != '\n')
            str += ch;
        if(str == "exit")
        {
            std::cout << "\x1B[35mTexting\033[0m\n" << std::endl;
            break;
        }
        else std::cout << "Word input: " << str << std::endl;
    }
    std::cout << "CLI FINISHED" << std::endl;
    return;
}
