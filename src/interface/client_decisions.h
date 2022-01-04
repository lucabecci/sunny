#include <cstring>
#include "../memory/managment.h"
#include "./message_interface.h"
class client_decisions : private message_interface
{
    private:
        managment m;
        void help(void);
    public:
        void cmd(std::string command);
};


void client_decisions::cmd(std::string command)
{
    std::string validate_process;
    if(command == "help")
    {
        help();
    }
    else if(command == "exit")
    {
        validate_process = m.pst("exit");
    }
    else if(command == "disconnect")
    {
        validate_process = m.pst("disconnect");
    }
    else
    {
        validate_process = m.validate(command);
    }
    __stdoutp(validate_process, "SUCCESS"); 
    return;
}

void client_decisions::help(void)
{
    std::cout << "- memory" << std::endl;
    std::cout << "- dms" << std::endl;
    std::cout << "- clear cache" << std::endl;
    return;
}
