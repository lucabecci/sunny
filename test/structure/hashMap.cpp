#include<cstring>
#include<cassert>
#include "../../src/structure/hashMap.h"


int main(int argc, char *argcv[])
{
  hashMap hmap;
  hmap.put("1", "A");
  hmap.put("2", "B");
  std::string value = hmap.get("2");
  hmap.put("2", "Updated");
  std::string updated = hmap.get("2");
  assert(value, "B");
  assert(updated, "Updated");
}
