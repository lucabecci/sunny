#pragma once

#include <memory>
#include <unordered_map>

template <typename K, typename V>
class hashMap
{
  private:
    std::unordered_map<K, V> hmap;
  public:
    hashMap(K key_type, V value_type)
    {
      if(!key_type || !value_type)
      {
        std::cout << "Error" << std::endl;
        return;
      }
      hmap = std::unordered_map<key_type, value_type>;
    }
    V get(K key)
    {
      
    }
    void put(K key, V value);
    void remove(K key);
};
