#ifndef UID_H
#define UID_H


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


#endif
