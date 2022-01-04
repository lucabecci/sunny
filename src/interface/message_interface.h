#include<cstring>
#include "../utils/colors.h"
class message_interface
{
    private:
        colors colors_process;
    public:
        void stdout(std::string message, std::string type);
};


void message_interface::stdout(std::string message, std::string type)
{
    std::string color = colors_process.change(0);
    if(type == "NORMAL") std::cout << colors_process.change(0) << message;
    else if(type == "ERROR") std::cout << colors_process.change(1) << message;
    else if(type == "WARNING") std::cout << colors_process.change(2) << message;
    else if(type == "SUCCESS") std::cout << colors_process.change(3) << message;
    else if(type == "INFO") std::cout << colors_process.change(4) << message;
    else 
    {
        std::cout << colors_process.change(1) << "Color not found"<< std::endl;
        std::cout << colors_process.change(0) << message;
    }
    std::cout << colors_process.change(0) << std::endl;
    return;
}


