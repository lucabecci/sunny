#include<cstring>
#include "./LRU_cache.h"

class querys 
{
  private:
    LRU_cache<std::string, std::string> lru;
  public:
    std::string get(std::string key)
    {
      std::string v = lru.get(key);
      return v;
    }
    bool put(std::string key, std::string value)
    {
      lru.put(key, value);
      return true;
    }
};
