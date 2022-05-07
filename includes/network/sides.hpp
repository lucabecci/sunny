#ifndef SIDES_H
#define SIDES_H


std::mutex mtx;
std::condition_variable cv;

class sides
{
    private: 
        void thread_client(void);
        void thread_server(void);
    public: 
        int process(void);
};

#endif