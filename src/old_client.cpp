#include<bits/stdc++.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>

#define PORT 8080

int main(int argc, char *argv[], char **envp)
{ 
  //Variables y creacion del socket
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from client";
  char buffer[1024] = {0};
  //Validando la creacion del socket
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    std::cout << "Socket creation error" << std::endl;
  }

  //Variable de serv_addr
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  //Convirtiendo IPv4 a IPv6 address de texto a binario
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  {
    std::cout << "Invalid address" << "--- Address not supported" << std::endl;
    return -1;
  }
  //Validando la conexion al server socket
  if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    std::cout << "Connection failed" << std::endl;
    return -1;
  }
  //Enviando mensaje buffer al server
  send(sock, hello, strlen(hello), 0);
  std::cout << "Hello message sent" << std::endl;
  //Leyendo valor buffer recibido automaticamente por el servere
  valread = read(sock, buffer, 1024);
  std::cout << buffer << std::endl;
  return 0;
}
