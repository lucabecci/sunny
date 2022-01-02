#include<iostream>
#include "../network/server.h"
#include "../globals.h"

int main(int argc, char *argv[]){
    server s;
    s.connection();
    connfd = s.connfd;
    s.process();
    return 0;
}
