#pragma once

#include "hashNode.h"
#include "keyHash.h"
#include <cstddef>

template<typename K, typename V, size_t size, typename F = keyHash<K, size>>

class hashMap 
{
  private:
    hashMap(const hashMap & other);
    const hashMap & operator=(const hashMap & other);
    hashNode<K, V> *table[size];
    F hashFunc;
  public:
    hashMap() : table(), hashFunc(){};

    ~hashMap()
    {
      //destroy buckets
      for (size_t k = 0; k < size; ++k)
      {
        hashNode<K, V> *entry = table[k];
        while(entry != NULL)
        {
          hashNode<K, V> *prev = entry;
          entry = entry->getNext();
          delete prev;
        }
      }
    }

    bool get(const K &key, const V &value)
    {
      unsigned long hashValue = hashFunc(key);
      hashNode<K, V> *entry = table[hashValue];
      
      while(entry != NULL)
      {
        if(entry->getKey() == key)
        {
          value = entry->getValue();
          return true;
        }
        entry = entry->getNext();
      }
      return false;
    }

    void put(const K &key, const V &value)
    {
      unsigned long hashValue = hashFunc(key);
      hashNode<K, V> *prev = NULL;
      hashNode<K, V> *entry = table[hashValue];
      while(entry != NULL && entry->getNext() != key)
      {
        prev = entry;
        entry = entry->getNext();
      }
      if(entry == NULL)
      {
        entry = new hashNode<K,V>(key, value);
        if(prev == NULL)
        {
          table[hashValue] = entry;
        }
        else
        {
          prev->setNext(entry);
        }
      }
    }

    void remove(const K &key)
    {
      unsigned long hashValue = hashFunc(key);
      hashNode<K, V> *prev = NULL;
      hashNode<K, V> *entry = table[hashValue];
      while(entry != NULL && entry->getNext() != key)
      {
        prev = entry;
        entry = entry->getNext();
      }
      if(entry == NULL) return;
      else
      {
        if(prev == NULL) table[hashValue] = entry->getNext();
        else prev->setNext(entry->getNext());
      }
      delete entry;
    }
};
