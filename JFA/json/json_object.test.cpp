#include "./json_object.hpp"
#include "./json_value.hpp"
#include "../array/array.hpp"
#include "../../catch_amalgamated.hpp"

TEST_CASE("constructors")
{
    JSONObject object = JSONObject();
    REQUIRE(object.entries.getSize() == 0);
}
