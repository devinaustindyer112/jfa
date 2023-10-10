#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"

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

    JSONValue value4 = JSONValue(JSONObject("key", JSONValue("value")));
    REQUIRE(value4.type == JSONValue::Type::OBJECT);

    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(JSONValue("Hello"));
    array->push(JSONValue("World"));
    JSONValue value5 = JSONValue(array);
    REQUIRE(value5.type == JSONValue::Type::ARRAY);
    JFA::String str1 = value5.array->get(0).string;
    JFA::String str2 = value5.array->get(1).string;
    REQUIRE(str1 == "Hello");
    REQUIRE(str2 == "World");
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
    JSONObject object = JSONObject("key", JSONValue("value"));
    JSONValue value = JSONValue(object);
    JSONValue value2 = value.get("key");
    REQUIRE(value2.string == "value");

    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(JSONValue("Hello"));
    array->push(JSONValue("World"));
    JSONValue value3 = JSONValue(array);
    JSONValue value4 = value3.get(0);
    REQUIRE(value4.string == "Hello");
}