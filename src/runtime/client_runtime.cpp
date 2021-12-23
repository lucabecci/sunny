#include<bits/stdc++.h>
#include "./network/client.h"

int main(int argc, char *argv[]){
    client c;
    std::cout << "Creating instance of the client side network" << std::endl;
    c.connection();
    return 0;
}
