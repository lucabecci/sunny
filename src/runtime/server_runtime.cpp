#include<iostream>
#include "../network/server.h"
#include "../globals.h"

int main(int argc, char *argv[]){
    server s;
    s.connection();
    s.process();
    return 0;
}
