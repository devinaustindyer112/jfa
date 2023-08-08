#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("Object", "[Object]")
{
    Array<JSONValue> *arr = new Array<JSONValue>();
    JSONValue *val1 = new JSONValue("foo");
    arr->push(val1);
    arr->push(val1);
    arr->push(val1);
    JSONValue *val2 = new JSONValue(arr);
    JSONObject *obj1 = new JSONObject("bar", val2);
    JSONValue *val3 = new JSONValue(obj1);
    JSONObject *obj2 = new JSONObject("baz", val3);

    JSONValue val = obj2->get("baz");
    val.print();

    // Need to make sure I'm handling the memory correctly and consistently.
}

TEST_CASE("Nested value equals", "[Nested value equals]")
{
    Array<JSONValue> *arr = new Array<JSONValue>();
    JSONValue *val1 = new JSONValue("foo");
    arr->push(val1);
    arr->push(val1);
    arr->push(val1);
    JSONValue *val2 = new JSONValue(arr);
    JSONObject *obj1 = new JSONObject("bar", val2);
    JSONValue *val3 = new JSONValue(obj1);
    JSONObject *obj2 = new JSONObject("baz", val3);

    JSONValue val = obj2->get("bar");
    REQUIRE(val.equals(val2));
}

TEST_CASE("Nested value equals different value", "[Nested value equals different value]")
{
    Array<JSONValue> *arr = new Array<JSONValue>();
    JSONValue *val1 = new JSONValue("foo");
    arr->push(val1);
    arr->push(val1);
    arr->push(val1);
    JSONValue *val2 = new JSONValue(arr);
    JSONObject *obj1 = new JSONObject("bar", val2);
    JSONValue *val3 = new JSONValue(obj1);
    JSONObject *obj2 = new JSONObject("baz", val3);

    JSONValue *val4 = new JSONValue(arr);

    JSONValue val = obj2->get("bar");
    REQUIRE(val.equals(val4));
}

TEST_CASE("Nested value not equal to different value", "[Nested value not equal to different value]")
{
    Array<JSONValue> *arr1 = new Array<JSONValue>();
    JSONValue *val1 = new JSONValue("foo");
    arr1->push(val1);
    arr1->push(val1);
    arr1->push(val1);
    JSONValue *val2 = new JSONValue(arr1);
    JSONObject *obj1 = new JSONObject("bar", val2);
    JSONValue *val3 = new JSONValue(obj1);
    JSONObject *obj2 = new JSONObject("baz", val3);

    Array<JSONValue> *arr2 = new Array<JSONValue>();
    JSONValue *val4 = new JSONValue("fuz");
    arr2->push(val4);
    arr2->push(val4);
    arr2->push(val4);
    JSONValue val5 = new JSONValue(arr2);

    JSONValue val = obj2->get("bar");
    REQUIRE(!val.equals(val4));
}