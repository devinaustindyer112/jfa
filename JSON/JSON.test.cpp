#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("object", "[object]")
{
    JSONObject obj2 = JSONObject("foo", JSONValue(new JSONObject("ban", JSONValue("baz"))));
    obj2.print();
}