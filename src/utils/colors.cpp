#include <cstring>
#include "../../includes/utils/colors.hpp"

#define WHITE   "\033[0m"       /* White */
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

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
        case 5:
            return WHITE;
        case 6: 
            return RED;
        case 7:
            return YELLOW;
        case 8:
            return GREEN;
        case 9:
            return BLUE;
        case 10:
            return MAGENTA;
        case 11:
            return CYAN;
        default:
            return BOLDWHITE;
    }
}
