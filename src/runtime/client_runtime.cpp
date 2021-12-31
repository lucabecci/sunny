#include "../interface/cli.h"
#include "../network/singleton_client.h"
#include "../globals.h"
int main(int argc, char *argv[]){
    cli c;
    singleton_client *client = singleton_client::instance();
    std::cout << client->sockfd << std::endl;
    client->connection();
    sockfd = client->sockfd;
    std::cout << sockfd << std::endl;
    for(;;)
    {
        int end = c.run();
        if(end)
        {
        std::cout << "Client exit..." << std::endl;
        break;
        }
    }
    return 0;
}
