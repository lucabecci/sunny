#ifndef CLIENT_DECISIONS_H
#define CLIENT_DECISIONS_H


class client_decisions : public message_interface
{
    private:
        managment m;
        void help(void);
        void database_help(void);
        void dms_help(void);
        void creator_help(void);
    public:
        void cmd(std::string command);
};

#endif