#include "../../includes/structure/hashMap.hpp"

std::string hashMap::get(std::string key)
{
  std::unordered_map<std::string, std::string>::iterator v;
  v = hmap.find(key);
  if(v != hmap.end()){
    return v->second;
  }
  return "NULL_V_SUNNY";
}
void hashMap::put(std::string key, std::string value)
{
  hmap[key] = value;
  return;
};
bool hashMap::remove(std::string key)
{
  hmap.erase(key);
  return true;
};