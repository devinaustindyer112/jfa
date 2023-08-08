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

TEST_CASE("Nested get value", "[Nested get value]")
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
    val.equals(val2);

    // Need to make sure I'm handling the memory correctly and consistently.
}