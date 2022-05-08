#define CATCH_CONFIG_MAIN 

#include "../catch.hpp"
#include "../../src/utils/colors.cpp"

colors c;

TEST_CASE("get bold white", "[colors]")
{
    std::string color = c.change(0);
    REQUIRE(color == "\033[1m\033[37m" );
}

TEST_CASE("get cyan", "[colors]")
{
    std::string color = c.change(11);
    REQUIRE(color == "\033[36m" );
}

TEST_CASE("get magenta", "[colors]")
{
    std::string color = c.change(10);
    REQUIRE(color == "\033[35m" );
}
