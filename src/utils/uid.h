#include <random>
#include <sstream>

class uid
{   
    private:
        static std::random_device d;
        static std::mt19937 rng(d());
        std::uniform_int_distribution<int> dist(0, 15);
        const char *v = "0123456789abcdef";
        const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };
    public:
        std::string generate(void);
};


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
