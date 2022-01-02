#include<cstring>
#include "./hashMap.h"


class querys 
{
  private:
    hashMap hmap;
  public:
    std::string get(std::string key)
    {
      std::string v = hmap.get(key);
      return v;
    }
    bool put(std::string key, std::string value)
    {
      hmap.put(key, value);
      return true;
    }
    bool remove(std::string key)
    {
      bool deleted = hmap.remove(key);
      if(deleted) return true;
      else return false;
    }
};
