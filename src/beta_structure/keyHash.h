//one exec in all compilation
#pragma once 

//template for key<random type> size of the table
template<typename K, size_t tableSize>

struct keyHash
{
  /*
   * if the range of keys is small, 
   * then most of the table hash is not used and chains get longer 
  */
  unsigned long operator()(const K& key)const 
  {
    return reinterpret_cast<unsigned long>(key) % tableSize;
  }
};
