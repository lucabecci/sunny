
#include<cstring>
#include "../../includes/structure/querys.hpp"
#include "./LRU_cache.hpp"

std::string querys::get(std::string key)
{
  std::string v = lru.get(key);
  return v;
} 

bool querys::put(std::string key, std::string value)
{
  lru.put(key, value);
  return true;
}

