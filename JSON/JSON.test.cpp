#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

// ===================
// Write more tests! Need to make sure that everything is
// complete before continuing with parser.
// How can I cover all possibilities?
// ===================

TEST_CASE("JSONObect returns value")
{
    JSONObject *obj = new JSONObject("foo", new JSONValue("bar"));
    JSONValue val = obj->get("foo");
    REQUIRE(val.equals(new JSONValue("bar")));
}
