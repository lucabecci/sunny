#include <cstring>
#include "../memory/managment.h"
#include "./message_interface.h"
class client_decisions : public message_interface
{
    private:
        managment m;
        void help(void);
        void database_help(void);
        void dms_help(void);
        void creator_help(void);
    public:
        void cmd(std::string command);
};


void client_decisions::cmd(std::string command)
{
    std::string validate_process;
    std::string type;
    if(command == "help")
    {
        type = "NORMAL";
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
    database_help();
    std::cout << std::endl;
    dms_help();
    std::cout << std::endl;
    creator_help();
    return;
}

void client_decisions::database_help(void)
{
    __stdoutp("- DATABASE", "INFO");
    __stdoutp(" - put key value - This command will add up or update one key in the database", "NOT_BOLD_NORMAL");
    __stdoutp(" - get key - This command will find a key in the database", "NOT_BOLD_NORMAL");
    __stdoutp(" - remove key - This command will remove a key of the database", "NOT_BOLD_NORMAL");
}

void client_decisions::dms_help(void)
{
    __stdoutp("- DMS", "INFO");
    __stdoutp(" - DMS(Database memory save) is a future functionality for saving data of the memory in the file system every X hour", "NOT_BOLD_NORMAL");
}

void client_decisions::creator_help(void)
{
    __stdoutp("- CREATOR", "INFO");
    __stdoutp(" - Name: Luca Becci", "NOT_BOLD_NORMAL");
    __stdoutp(" - Github: Luca Becci", "NOT_BOLD_NORMAL");
    __stdoutp(" - Linkedin: Luca Becci", "NOT_BOLD_NORMAL");
}