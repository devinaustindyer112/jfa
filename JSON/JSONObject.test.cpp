#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructors")
{
    JSONObject object = JSONObject();
    REQUIRE(object.entries.getSize() == 0);
}
