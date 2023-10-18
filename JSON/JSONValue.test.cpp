#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("constructors")
{
    JSONValue val1 = JSONValue();
    REQUIRE(val1.type == JSONValue::Type::NULL_VALUE);

    JSONValue val2 = JSONValue("Hello");
    REQUIRE(val2.type == JSONValue::Type::STRING);
}
