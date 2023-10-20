#include "Utilities.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("size")
{
    REQUIRE(size("\"\"\"\"") == 4);
    REQUIRE(size("test") == 4);
    REQUIRE(size("") == 0);
}

TEST_CASE("equals")
{
    REQUIRE(strCompare("test", "test"));
    REQUIRE(!strCompare("test", "false"));
    REQUIRE(!strCompare("te", "test"));
}