#ifndef CLI_H
#define CLI_H


class cli
{
    private:
        int sock;
        void initial_information(void);
        void name(void);
        client_decisions d;
    public:
        cli(void);
        int run(void);        
};

#endif