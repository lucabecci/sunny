#include "../interface/cli.h"
#include "../network/client.h"
#include "../globals.h"
int main(int argc, char *argv[]){
    cli c;
    client *client = client::instance();
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
