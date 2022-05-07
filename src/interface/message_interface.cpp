#include<cstring>
#include "../utils/colors.cpp"
#include "../../includes/interface/message_interface.hpp"

void message_interface::stdout(std::string message, std::string type)
{
    std::string color = colors_process.change(0);
    if(type == "NORMAL") std::cout << colors_process.change(0) << message;
    else if(type == "ERROR") std::cout << colors_process.change(1) << message;
    else if(type == "WARNING") std::cout << colors_process.change(2) << message;
    else if(type == "SUCCESS") std::cout << colors_process.change(3) << message;
    else if(type == "INFO") std::cout << colors_process.change(4) << message;
    else if(type == "NOT_BOLD_NORMAL") std::cout << colors_process.change(5) << message;
    else if(type == "NOT_BOLD_ERROR") std::cout << colors_process.change(6) << message;
    else if(type == "NOT_BOLD_WARNING") std::cout << colors_process.change(7) << message;
    else if(type == "NOT_BOLD_SUCCESS") std::cout << colors_process.change(8) << message;
    else if(type == "NOT_BOLD_INFO") std::cout << colors_process.change(9) << message;
    else if(type == "MAGENTA") std::cout << colors_process.change(10) << message;
    else if(type == "CYAN") std::cout << colors_process.change(11) << message;
    else 
    {
        std::cout << colors_process.change(5) << "Color not found"<< std::endl;
        std::cout << colors_process.change(0) << message;
    }
    std::cout << colors_process.change(5) << std::endl;
    return;
}


