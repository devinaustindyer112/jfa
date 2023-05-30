#include "Utilities.h"
#include "../catch_amalgamated.hpp"

TEST_CASE("size", "[size]")
{
    REQUIRE(size("test") == 4);
    REQUIRE(size("") == 0);
}