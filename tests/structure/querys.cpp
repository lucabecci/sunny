#define CATCH_CONFIG_MAIN 

#include "../catch.hpp"
#include "../../src/structure/querys.cpp"

querys q;

TEST_CASE("query get - found", "[LRU]")
{
    q.put("X", "ABC");
    std::string v = q.get("X");
    REQUIRE(v == "ABC");
}


TEST_CASE("query get - not found", "[LRU]")
{
    q.put("EXIST", "ABC");
    std::string v = q.get("NOT_FOUND");
    REQUIRE(v == "NULL_V_SUNNY");
}


TEST_CASE("query put - second", "[LRU]")
{
    REQUIRE(q.put("x", "123") == true);
}
