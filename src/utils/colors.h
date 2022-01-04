#include <cstring>

#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class colors
{
    public:
        std::string change(int type);
};

std::string colors::change(int type)
{
    switch(type)
    {
        case 0:
            return BOLDWHITE;
        case 1:
            return BOLDRED;
        case 2:
            return BOLDYELLOW;
        case 3:
            return BOLDGREEN;
        case 4: 
            return BOLDBLUE;
        default:
            return BOLDWHITE;
    }
}
