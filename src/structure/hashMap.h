#pragma once

#include<bits/stdc++.h>
#include <memory>
#include <unordered_map>
#include<cstring>
class hashMap
{
  public:
    std::unordered_map<std::string, std::string> hmap;
    std::string get(std::string key)
    {
      std::unordered_map<std::string, std::string>::iterator v;
      v = hmap.find(key);
      if(v != hmap.end()){
        return v->second;
      }
      return NULL;
    }
    void put(std::string key, std::string value)
    {
      hmap[key] = value;
      return;
    };
    void remove(std::string key)
    {
      hmap.erase(key);
      return;
    };
};
