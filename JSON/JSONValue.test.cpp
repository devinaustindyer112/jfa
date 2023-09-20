#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

// Write smart comprehensive tests
// Follow the pattern of the tests in String.test.cpp

// ==========
// Start here
// ==========

TEST_CASE("constructors")
{
    JSONValue value = JSONValue();
    REQUIRE(value.type == JSONValue::Type::NULL_VALUE);
    REQUIRE(value.string == "");
    REQUIRE(value.object == nullptr);
    REQUIRE(value.array == nullptr);

    JSONValue value2 = JSONValue("Hello");
    REQUIRE(value2.type == JSONValue::Type::STRING);
    REQUIRE(value2.string == "Hello");

    JSONValue value3 = value2;
    REQUIRE(value3.type == JSONValue::Type::STRING);
    REQUIRE(value3.string == "Hello");
}

TEST_CASE("assignment operator")
{
    JSONValue value = JSONValue("Hello");
    JSONValue value2 = JSONValue("World");
    value = value2;
    REQUIRE(value.type == JSONValue::Type::STRING);
    REQUIRE(value.string == "World");
}

TEST_CASE("get")
{
    // Works
    // JSONValue val = JSONValue(JSONObject("key", JSONValue("value")));
    // val.type;

    // Breaks
    // JSONObject obj = JSONObject("key", JSONValue("value"));
    // JSONValue val2 = JSONValue(obj);

    // value.type;
    // value.object->print();
    // REQUIRE(value.object->equals(JSONObject("key", JSONValue("value"))));
    //  REQUIRE(!(value.object->equals(JSONObject("key", JSONValue("wrong value")))));

    // JSONValue value2 = value.get("key");
    // REQUIRE(value2 == JSONValue("value"));
    // REQUIRE(!(value2 == JSONValue("wrong value")));

    // Array<JSONValue> *array = new Array<JSONValue>();
    // array->push();
}