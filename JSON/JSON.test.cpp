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

// TEST_CASE("JSONObect returns value")
// {
//     JSONObject *obj = new JSONObject("foo", new JSONValue("bar"));
//     JSONValue val = obj->get("foo");
//     REQUIRE(val.equals(new JSONValue("bar")));
// }

// TEST_CASE("JSONObect returns nested value")
// {
//     JSONObject *obj1 = new JSONObject("foo", new JSONValue("bar"));
//     JSONObject *obj2 = new JSONObject("baz", new JSONValue(obj1));
//     JSONValue val = obj2->get("baz");
//     REQUIRE(val.equals(new JSONValue(obj1)));
// }

// TEST_CASE("String JSONValue returns nullptr on get")
// {
//     JSONValue *val = new JSONValue("foo");
//     REQUIRE(val->get("foo") == nullptr);
// }

// TEST_CASE("Obect JSONValue returns correct value")
// {
//     JSONObject *obj = new JSONObject("foo", new JSONValue("bar"));
//     JSONValue *val = new JSONValue(obj);
//     REQUIRE(val->get("foo")->equals(new JSONValue("bar")));
// }

TEST_CASE("Array JSONValue returns correct value")
{
    Array<JSONValue> *arr = new Array<JSONValue>();
    JSONObject *obj = new JSONObject("foo", new JSONValue("var"));
    JSONValue *val1 = new JSONValue(obj);
    arr->push(val1);
    JSONValue *val2 = new JSONValue(arr);

    // I think i need a deep copy where there is a shallow copy.
    // Trying to access a value/object that has already been deleted.
    // The array/using shallow copy is likely the problem.
    JSONValue *actual = val2->get("foo");
    REQUIRE(actual->equals(new JSONValue("var")));
}

// Adding a new copy constructor to JSONObject and JSONValue