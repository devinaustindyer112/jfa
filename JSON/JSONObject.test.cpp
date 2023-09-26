#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("constructors")
{
    JSONObject object = JSONObject();
    REQUIRE(object.key == "");
    REQUIRE(object.value == nullptr);

    JSONObject object2 = JSONObject("key", JSONValue("value"));
    REQUIRE(object2.key == "key");
    REQUIRE(object2.value->string == "value");

    JSONObject object3 = object2;
    REQUIRE(object3.key == "key");
    REQUIRE(object3.value->string == "value");
}

TEST_CASE("assignment operator")
{
    JSONObject object = JSONObject("key", JSONValue("value"));
    JSONObject object2 = JSONObject("key2", JSONValue("value2"));
    object = object2;
    REQUIRE(object.key == "key2");
    REQUIRE(object.value->string == "value2");
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

// Keep working on the testing JSON and array classes. Need to focus more
// on handling cases where there or nullpointers and similar cases.