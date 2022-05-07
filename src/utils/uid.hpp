#include <random>
#include <sstream>
#include "../../includes/utils/uid.hpp"

std::string uid::generate(void)
{
    std::string r;
    for (int i = 0; i < 16; i++) {
        if (dash[i]) r += "-";
        r += v[dist(rng)];
        r += v[dist(rng)];
    }
    return r;
}
