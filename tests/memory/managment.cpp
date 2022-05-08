int sockfd = 2000;

#define CATCH_CONFIG_MAIN 

#include "../catch.hpp"
#include "../../src/memory/managment.cpp"

managment m;
std::string test_cases[3] = {"put X b", "get X a", "err X b"};
int length = sizeof(test_cases)/sizeof(test_cases[0]);
TEST_CASE("method first - get", "[managment]")
{
    std::string corrects[3] = {"", "", "Invalid command"}; 
    for (size_t i = 0; i < length; i++)
    {
        REQUIRE(m.validate(test_cases[i]) == corrects[i]);
    }
}


TEST_CASE("method pst", "[managment]")
{
    for (size_t i = 0; i < length; i++)
    {
        REQUIRE(m.pst(test_cases[i], true) == "");
    }
}

