#include "../interface/cli.h"
#include "../network/singleton_client.h"
#include "../globals.h"
int main(int argc, char *argv[]){
    cli c;
    singleton_client *client = singleton_client::instance();
    client->connection();
    sockfd = client->sockfd;
    for(;;)
    {
        int end = c.run();
        if(end)
        {
        break;
        }
    }
    return 0;
}
