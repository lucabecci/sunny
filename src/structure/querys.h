#include<cstring>
#include "./hashMap.h"


class querys 
{
  private:
    hashMap hmap;
  public:
    std::string get(std::string key)
    {
      return hmap.get(key);
    }
    void put(std::string key, std::string value)
    {
      hmap.put(key, value);
      return;
    }
    void remove(std::string key)
    {
      hmap.remove(key);
      return;
    }
};
