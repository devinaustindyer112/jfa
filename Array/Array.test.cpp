#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

template class Array<String>;

// TEST_CASE("constructer with pointer to other array", "[Array]")
// {
//     Array<String> *array = new Array<String>();
//     array->push(new String("Hello"));
//     array->push(new String("World"));
//     Array<String> *other = new Array<String>(array);
//     REQUIRE(other->length() == 2);
//     REQUIRE(other->get(1).equals(String("World")));
//     REQUIRE(other->get(0).equals(String("Hello")));
//     delete array;
//     delete other;
// }

// TEST_CASE("same test but with JSONObects that have JSONValues", "[Array]")
// {
//     Array<JSONObject> *array = new Array<JSONObject>();
//     array->push(new JSONObject(String("Hello"), new JSONValue(String("World"))));
//     array->push(new JSONObject(String("World"), new JSONValue(String("Hello"))));
//     Array<JSONObject> *other = new Array<JSONObject>(array);
//     REQUIRE(other->length() == 2);
//     REQUIRE(other->get(1).equals(JSONObject(String("World"), new JSONValue(String("Hello")))));
//     REQUIRE(other->get(0).equals(JSONObject(String("Hello"), new JSONValue(String("World")))));
//     delete array;
//     delete other;
// }

// TEST_CASE("same test but with JSONValues that have strings", "[Array]")
// {
//     Array<JSONValue> *array = new Array<JSONValue>();
//     array->push(new JSONValue(String("Hello")));
//     array->push(new JSONValue(String("World")));
//     Array<JSONValue> *other = new Array<JSONValue>(array);
//     REQUIRE(other->length() == 2);
//     REQUIRE(other->get(1).equals(JSONValue(String("World"))));
//     REQUIRE(other->get(0).equals(JSONValue(String("Hello"))));
//     delete array;
//     delete other;
// }

TEST_CASE("same test but with JSONValues that have JSONObjects", "[Array]")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(new JSONObject(String("Hello"), new JSONValue(String("World")))));
    // array->push(new JSONValue(new JSONObject(String("World"), new JSONValue(String("Hello")))));
    // Array<JSONValue> *other = new Array<JSONValue>(array);
    // REQUIRE(other->length() == 2);
    // REQUIRE(other->get(1).equals(JSONValue(new JSONObject(String("World"), new JSONValue(String("Hello"))))));
    // REQUIRE(other->get(0).equals(JSONValue(new JSONObject(String("Hello"), new JSONValue(String("World"))))));
    // delete array;
    // delete other;
}