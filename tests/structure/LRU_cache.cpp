#define CATCH_CONFIG_MAIN 

#include "catch.hpp"
#include "../../src/structure/LRU_cache.hpp"

LRU_cache< std::string, std::string > lru;

TEST_CASE("put and get value in the lru - first", "[LRU]")
{
    lru.put("Key_V", "string_to_find");
    REQUIRE(lru.get("Key_V") == "string_to_find");
}

TEST_CASE("put and get value in the lru - second", "[LRU]")
{
    lru.put("ERR_KV", "A");
    REQUIRE(lru.get("ERR_KV") != "2");
}

TEST_CASE("put and get value in the lru - third", "[LRU]")
{
    REQUIRE(lru.get("NOT_KV") == "NULL_V_SUNNY");
}

