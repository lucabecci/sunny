#include<iostream>
#include "../src/network/server.cpp"
#include "../src/globals.h"

int main(int argc, char *argv[]){
    server s;
    s.connection();
    s.process();
    return 0;
}
