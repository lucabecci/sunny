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
    std::string type;
    if(command == "help")
    {
        type = "NORMAL"
        help();
    }
    else if(command == "exit")
    {
        type = "WARNING";
        validate_process = m.pst("exit");
    }
    else if(command == "disconnect")
    {
        type = "WARNING";
        validate_process = m.pst("disconnect");
    }
    else
    {
        type = "NORMAL";
        validate_process = m.validate(command);
        if(validate_process == "Invalid command") type = "ERROR";

    }
    __stdoutp(validate_process, type); 
    return;
}

void client_decisions::help(void)
{
    std::cout << "- memory" << std::endl;
    std::cout << "- dms" << std::endl;
    std::cout << "- clear cache" << std::endl;
    return;
}
