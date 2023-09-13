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
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(new JFA::String("Hello"));
    array->push(new JFA::String("World"));
    array->push(new JFA::String("!"));
    Array<JFA::String> *other = new Array<JFA::String>();
    other->push(new JFA::String("Hello"));
    other->push(new JFA::String("World"));
    other->push(new JFA::String("!"));
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array equals - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(JFA::String("Hello")));
    array->push(new JSONValue(JFA::String("World")));
    array->push(new JSONValue(JFA::String("!")));
    Array<JSONValue> *other = new Array<JSONValue>();
    other->push(new JSONValue(JFA::String("Hello")));
    other->push(new JSONValue(JFA::String("World")));
    other->push(new JSONValue(JFA::String("!")));
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
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(new JFA::String("Hello"));
    array->push(new JFA::String("World"));
    array->push(new JFA::String("!"));
    array->get(0).equals(JFA::String("Hello"));
    REQUIRE(array->get(0).equals(JFA::String("Hello")));
    REQUIRE(array->get(1).equals(JFA::String("World")));
    REQUIRE(array->get(2).equals(JFA::String("!")));
    delete array;
}

TEST_CASE("Array push/get - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(JFA::String("Hello")));
    array->push(new JSONValue(JFA::String("World")));
    array->push(new JSONValue(JFA::String("!")));
    REQUIRE(array->get(0).equals(JSONValue(JFA::String("Hello"))));
    REQUIRE(array->get(1).equals(JSONValue(JFA::String("World"))));
    REQUIRE(array->get(2).equals(JSONValue(JFA::String("!"))));
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
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(JFA::String("Hello"));
    array->push(JFA::String("World"));
    array->push(JFA::String("!"));
    array->get(0).equals(JFA::String("Hello"));
    REQUIRE(array->get(0).equals(JFA::String("Hello")));
    REQUIRE(array->get(1).equals(JFA::String("World")));
    REQUIRE(array->get(2).equals(JFA::String("!")));
    delete array;
}

TEST_CASE("Array deoesn't equal - String")
{
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(new JFA::String("Hello"));
    array->push(new JFA::String("World"));
    array->push(new JFA::String("!"));
    Array<JFA::String> *other = new Array<JFA::String>();
    other->push(new JFA::String("Hello"));
    other->push(new JFA::String("World"));
    other->push(new JFA::String("?"));
    REQUIRE(!array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array doesn't equal - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(JFA::String("Hello")));
    array->push(new JSONValue(JFA::String("World")));
    array->push(new JSONValue(JFA::String("!")));
    Array<JSONValue> *other = new Array<JSONValue>();
    other->push(new JSONValue(JFA::String("Hello")));
    other->push(new JSONValue(JFA::String("World")));
    other->push(new JSONValue(JFA::String("?")));
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
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(new JFA::String("Hello"));
    array->push(new JFA::String("World"));
    array->push(new JFA::String("!"));
    Array<JFA::String> *other = new Array<JFA::String>(array);
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array copy constructor - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(JFA::String("Hello")));
    array->push(new JSONValue(JFA::String("World")));
    array->push(new JSONValue(JFA::String("!")));
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
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(new JFA::String("Hello"));
    array->push(new JFA::String("World"));
    array->push(new JFA::String("!"));
    Array<JFA::String> *other = new Array<JFA::String>(array);
    REQUIRE(array->equals(other));
    delete array;
    delete other;
}

TEST_CASE("Array pop - String")
{
    Array<JFA::String> *array = new Array<JFA::String>();
    array->push(new JFA::String("Hello"));
    array->push(new JFA::String("World"));
    array->push(new JFA::String("!"));
    REQUIRE(array->pop().equals(JFA::String("!")));
    REQUIRE(array->pop().equals(JFA::String("World")));
    REQUIRE(array->pop().equals(JFA::String("Hello")));
    delete array;
}

TEST_CASE("Array pop - JSONValue")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    array->push(new JSONValue(JFA::String("Hello")));
    array->push(new JSONValue(JFA::String("World")));
    array->push(new JSONValue(JFA::String("!")));
    REQUIRE(array->pop().equals(JSONValue(JFA::String("!"))));
    REQUIRE(array->pop().equals(JSONValue(JFA::String("World"))));
    REQUIRE(array->pop().equals(JSONValue(JFA::String("Hello"))));
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
