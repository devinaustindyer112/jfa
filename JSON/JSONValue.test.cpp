#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructors")
{
    JSONValue val2 = JSONValue("Hello");
    REQUIRE(val2.type == JSONValue::Type::STRING);
}
