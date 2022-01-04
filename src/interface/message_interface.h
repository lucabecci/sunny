#include<cstring>
#include "../utils/colors.h"

#define BOLDWHITE   0      /* Bold White */
#define BOLDRED     1      /* Bold Red */
#define BOLDGREEN   2     /* Bold Green */
#define BOLDYELLOW  3     /* Bold Yellow */
#define BOLDBLUE    4      /* Bold Blue */

class message_interface
{
    private:
        colors colors_process;
    public:
        void stdout(std::string message, std::string type);
}


void message_interface::stdout(std::string message, std::string type)
{
    std::string color = colors_process.change(0);
    if(type == "NORMAL") scolors_process.change(0);
    else if(type == "ERROR") colors_process.change(1);
    else if(type == "SUCCESS") colors_process.change(2);
    else if(type == "WARNING") colors_process.change(3);
    else if(type == "INFO") colors_process.change(4);
    else 
    {
        std::cout << colors_process.change(1) << "Color not found"<< std::endl;
        colors_process.change(0);    
    }
    std::cout << message << std::endl;
    return;
}


