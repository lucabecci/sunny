#include <bits/stdc++.h>
#include <cstring>

enum CASES {
    HELP = 0,
};
class desition
{
    private:
        void configuration(void);
        void help(void);
    public:
        void cmd(std::string command);
};


void desition::cmd(std::string command)
{
    switch(command)
    {
        case "conf":
            configuration(void);
        case "help":
            help(void);
    }
}


