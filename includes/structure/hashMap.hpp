#ifndef HASHMAP_H
#define HASHMAP_H


class hashMap
{
  public:
    std::unordered_map<std::string, std::string> hmap;
    std::string get(std::string key);
    void put(std::string key, std::string value);
    bool remove(std::string key);
};


#endif