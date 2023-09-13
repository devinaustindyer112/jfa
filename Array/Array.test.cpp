#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

// A decent amount of these tests would be made redundant
// by writing proper tests for the String, JSONValue, and JSONObject classes.

TEST_CASE("Array equals - String")
{
    Array<String> *array = new Array<String>();
    array->push(new String("Hello"));
    array->push(new String("World"));
    array->push(new String("!"));
    Array<String> *other = new Array<String>();
    other->push(new String("Hello"));
    other->push(new String("World"));
    other->push(new String("!"));
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array equals - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(String("Hello")));
    array->push(new JSONValue(String("World")));
    array->push(new JSONValue(String("!")));
    Array<JSONValue> *other = new Array<JSONValue>();
    other->push(new JSONValue(String("Hello")));
    other->push(new JSONValue(String("World")));
    other->push(new JSONValue(String("!")));
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array equals - JSONObject")
{
    Array<JSONObject> *array = new Array<JSONObject>();
    array->push(new JSONObject());
    array->push(new JSONObject());
    array->push(new JSONObject());
    Array<JSONObject> *other = new Array<JSONObject>();
    other->push(new JSONObject());
    other->push(new JSONObject());
    other->push(new JSONObject());
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array push/get - String")
{
    Array<String> *array = new Array<String>();
    array->push(new String("Hello"));
    array->push(new String("World"));
    array->push(new String("!"));
    array->get(0).equals(String("Hello"));
    REQUIRE(array->get(0).equals(String("Hello")));
    REQUIRE(array->get(1).equals(String("World")));
    REQUIRE(array->get(2).equals(String("!")));
    delete array;
}

TEST_CASE("Array push/get - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(String("Hello")));
    array->push(new JSONValue(String("World")));
    array->push(new JSONValue(String("!")));
    REQUIRE(array->get(0).equals(JSONValue(String("Hello"))));
    REQUIRE(array->get(1).equals(JSONValue(String("World"))));
    REQUIRE(array->get(2).equals(JSONValue(String("!"))));
    delete array;
}

TEST_CASE("Array push/get - JSONObject")
{
    Array<JSONObject> *array = new Array<JSONObject>();
    array->push(new JSONObject());
    array->push(new JSONObject());
    array->push(new JSONObject());
    REQUIRE(array->get(0).equals(JSONObject()));
    REQUIRE(array->get(1).equals(JSONObject()));
    REQUIRE(array->get(2).equals(JSONObject()));
    delete array;
}

TEST_CASE("Array push/get - by String value")
{
    Array<String> *array = new Array<String>();
    array->push(String("Hello"));
    array->push(String("World"));
    array->push(String("!"));
    array->get(0).equals(String("Hello"));
    REQUIRE(array->get(0).equals(String("Hello")));
    REQUIRE(array->get(1).equals(String("World")));
    REQUIRE(array->get(2).equals(String("!")));
    delete array;
}

TEST_CASE("Array deoesn't equal - String")
{
    Array<String> *array = new Array<String>();
    array->push(new String("Hello"));
    array->push(new String("World"));
    array->push(new String("!"));
    Array<String> *other = new Array<String>();
    other->push(new String("Hello"));
    other->push(new String("World"));
    other->push(new String("?"));
    REQUIRE(!array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array doesn't equal - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(String("Hello")));
    array->push(new JSONValue(String("World")));
    array->push(new JSONValue(String("!")));
    Array<JSONValue> *other = new Array<JSONValue>();
    other->push(new JSONValue(String("Hello")));
    other->push(new JSONValue(String("World")));
    other->push(new JSONValue(String("?")));
    REQUIRE(!array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array doesn't equal - JSONObject")
{
    Array<JSONObject> *array = new Array<JSONObject>();
    array->push(new JSONObject());
    array->push(new JSONObject());
    array->push(new JSONObject());
    Array<JSONObject> *other = new Array<JSONObject>();
    other->push(new JSONObject());
    other->push(new JSONObject());
    REQUIRE(!array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array copy constructor - String")
{
    Array<String> *array = new Array<String>();
    array->push(new String("Hello"));
    array->push(new String("World"));
    array->push(new String("!"));
    Array<String> *other = new Array<String>(array);
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array copy constructor - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(String("Hello")));
    array->push(new JSONValue(String("World")));
    array->push(new JSONValue(String("!")));
    Array<JSONValue> *other = new Array<JSONValue>(array);
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array copy constructor - JSONObject")
{
    Array<JSONObject> *array = new Array<JSONObject>();
    array->push(new JSONObject());
    array->push(new JSONObject());
    array->push(new JSONObject());
    Array<JSONObject> *other = new Array<JSONObject>(array);
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array pointer constructor")
{
    Array<String> *array = new Array<String>();
    array->push(new String("Hello"));
    array->push(new String("World"));
    array->push(new String("!"));
    Array<String> *other = new Array<String>(array);
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array pop - String")
{
    Array<String> *array = new Array<String>();
    array->push(new String("Hello"));
    array->push(new String("World"));
    array->push(new String("!"));
    REQUIRE(array->pop().equals(String("!")));
    REQUIRE(array->pop().equals(String("World")));
    REQUIRE(array->pop().equals(String("Hello")));
    delete array;
}

TEST_CASE("Array pop - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(String("Hello")));
    array->push(new JSONValue(String("World")));
    array->push(new JSONValue(String("!")));
    REQUIRE(array->pop().equals(JSONValue(String("!"))));
    REQUIRE(array->pop().equals(JSONValue(String("World"))));
    REQUIRE(array->pop().equals(JSONValue(String("Hello"))));
    delete array;
}

TEST_CASE("Array pop - JSONObject")
{
    Array<JSONObject> *array = new Array<JSONObject>();
    array->push(new JSONObject());
    array->push(new JSONObject());
    array->push(new JSONObject());
    REQUIRE(array->pop().equals(JSONObject()));
    REQUIRE(array->pop().equals(JSONObject()));
    REQUIRE(array->pop().equals(JSONObject()));
    delete array;
}
