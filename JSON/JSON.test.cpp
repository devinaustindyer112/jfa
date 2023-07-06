#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("object", "[object]")
{
    JSONValue val1 = JSONValue("baz");
    JSONObject obj1 = JSONObject("ban", val1);

    obj1.print();
}