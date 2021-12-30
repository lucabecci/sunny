#include<bits/stdc++.h>
#include<cstring>
#include<cassert>
#include "../../src/structure/hashMap.h"
#include "../../src/structure/keyHash.h"

int main(int argc, char *argv[])
{
  hashMap<int, std::string, 8, keyHash<int, 8>> dict;
  std::string value;
  dict.put(1, "A");
  dict.get(1, value);
  std::cout << value << std::endl;
  return 0;
}
