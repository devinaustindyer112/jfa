#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("constructors")
{
    JSONObject object = JSONObject();
    REQUIRE(object.entries.getSize() == 0);
}

TEST_CASE("assignment operator")
{
    JSONObject object = JSONObject("key", JSONValue("value"));
    JSONObject object2 = JSONObject("key2", JSONValue("value2"));
    object = object2;
    REQUIRE(object.entries.getSize() == 1);
}

TEST_CASE("get")
{
    JSONObject object = JSONObject("key", JSONValue("value"));
    JSONValue value = object.get("key");
    REQUIRE(value.string == "value");
}

TEST_CASE("== operator")
{
    JSONObject object1 = JSONObject("key", JSONValue("value"));
    JSONObject object2 = JSONObject("key", JSONValue("value"));
    REQUIRE(object1 == object2);

    JSONObject object3 = JSONObject("key", JSONValue("value2"));
    REQUIRE(!(object2 == object3));
}