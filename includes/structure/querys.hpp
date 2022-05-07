#ifndef QUERYS_H
#define QUERYS_H


class querys 
{
  private:
    LRU_cache<std::string, std::string> lru;
  public:
    std::string get(std::string key);
    bool put(std::string key, std::string value);
};

#endif
