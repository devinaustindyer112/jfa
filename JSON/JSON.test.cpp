#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("object", "[object]")
{
    JSONObject obj = JSONObject("ban", JSONValue(JSONValue::Type::OBJECT, new JSONObject("ban", JSONValue(JSONValue::Type::STRING, "baz"))));

    obj.print();
}