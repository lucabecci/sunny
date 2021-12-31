#include "../network/singleton_client.h"
#include "../globals.h"
int main(int argc, char *argv[]){
    singleton_client *c = singleton_client::instance();
    std::cout << c->sockfd << std::endl;
    c->connection();
    return 0;
}
