#include<bits/stdc++.h>
#include<cstring>

#include "../../src/structure/hashMap.h"


int main(int argc, char *argcv[])
{
  hashMap hmap;
  hmap.put("1", "A");
  hmap.put("2", "B");
  std::string value = hmap.get("2");
  hmap.put("2", "Updated");
  std::string updated = hmap.get("2");
  std::cout << value << std::endl;
  std::cout << updated << std::endl;
}
