#include <memory>
#include<thread>
#include<mutex>
#include <condition_variable>
#include "./client.cpp"
#include "./erver.cpp"
#include "../../includes/network/sides.hpp"

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
