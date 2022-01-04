#include <memory>
#include<thread>
#include<mutex>
#include<condition_variable>
#include "./client.h"
#include "./server.h"

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


void sides::thread_client(void)
{
    client c;
    c.connection();
    return;
}


void sides::thread_server(void)
{
    server s;
    s.connection();
    return;
}


int sides::process(void)
{
    std::unique_lock<std::mutex> lck(mtx);
    std::thread t1(thread_client), t2(thread_server);
    
    cv.wait(lck);

    t1.join();
    t2.join();

    return 0;
}
