#ifndef CLIENT_H
#define CLIENT_H


#define PORT 8080
#define SA struct sockaddr

class client
{
  private:    
    client(){};
    client(client const&) {};
    client& operator=(client const&) {return *this;};
    static client * instance_;
  public:
    int sockfd;
    static client * instance();
    void connection(void);
    bool pst(std::string c);
};

#endif