#ifndef MESSAGE_INTERFACE_H
#define MESSAGE_INTERFACE_H


class message_interface
{
    private:
        colors colors_process;
    public:
        void stdout(std::string message, std::string type);
};

#endif