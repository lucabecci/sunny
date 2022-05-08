#define MAX_SVD 1024

#include "../structure/querys.hpp"


extern int connfd;
#ifndef SERVER_DECISIONS_H
#define SERVER_DECISIONS_H



class server_decisions
{
    private:
        std::vector<std::string> three_split(std::string command);
        querys q;
        char buff[MAX_SVD];
    public:
        void analyze(std::string command);
        void pst(std::string);
};

#endif