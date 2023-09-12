#include "./JSONObject.hpp"
#include "./JSONValue.hpp"
#include "../Array/Array.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

// JSONObject tests

TEST_CASE("JSONObject equals - by value")
{
    JSONObject *object = new JSONObject(String("key"), new JSONValue(String("value")));
    REQUIRE(object->equals(JSONObject(String("key"), new JSONValue(String("value")))));
}

TEST_CASE("JSONObject equals - by reference")
{
    JSONObject *object = new JSONObject(String("key"), new JSONValue(String("value")));
    JSONObject *other = new JSONObject(object);
    REQUIRE(object->equals(other));
}

TEST_CASE("JSONObject get")
{
    JSONObject *object = new JSONObject(String("key"), new JSONValue(String("value")));
    REQUIRE(object->get(String("key")).equals(new JSONValue(String("value"))));
}

TEST_CASE("JSONObject get - nested")
{
    JSONObject *object = new JSONObject(String("key"), new JSONValue(new JSONObject(String("key"), new JSONValue(String("value")))));
    REQUIRE(object->get("key").equals(new JSONValue(new JSONObject(String("key"), new JSONValue(String("value"))))));
}

TEST_CASE("JSONObject assignment operator")
{
    JSONObject *object = new JSONObject(String("key"), new JSONValue(String("value")));
    JSONObject *other = new JSONObject();
    *other = *object;
    REQUIRE(object->equals(other));
}

TEST_CASE("JSONObject copy constructor")
{
    JSONObject *object = new JSONObject(String("key"), new JSONValue(String("value")));
    JSONObject *other = new JSONObject(*object);
    REQUIRE(object->equals(other));
}

// JSONValue tests

TEST_CASE("JSONValue equals - by value")
{
    JSONValue *value = new JSONValue(String("value"));
    REQUIRE(value->equals(new JSONValue(String("value"))));
}

TEST_CASE("JSONValue equals - by reference")
{
    JSONValue *value = new JSONValue(String("value"));
    JSONValue *other = new JSONValue(value);
    REQUIRE(value->equals(other));
}

TEST_CASE("JSONValue array doesn't equals")
{
    Array<JSONValue> *array1 = new Array<JSONValue>();
    array1->push(new JSONValue(String("value")));
    array1->push(new JSONValue(String("value2")));
    JSONValue *value1 = new JSONValue(array1);

    Array<JSONValue> *array2 = new Array<JSONValue>();
    array2->push(new JSONValue(String("value")));
    JSONValue *value2 = new JSONValue(array2);

    REQUIRE(!value1->equals(value2));
}

TEST_CASE("JSONValue array equals")
{
    Array<JSONValue> *array1 = new Array<JSONValue>();
    array1->push(new JSONValue(String("value")));
    array1->push(new JSONValue(String("value2")));
    JSONValue *value1 = new JSONValue(array1);

    Array<JSONValue> *array2 = new Array<JSONValue>();
    array2->push(new JSONValue(String("value")));
    array2->push(new JSONValue(String("value2")));
    JSONValue *value2 = new JSONValue(array2);

    REQUIRE(value1->equals(value2));
}

TEST_CASE("JSONObject array get")
{
    Array<JSONValue> *array = new Array<JSONValue>();
    JSONObject *object1 = new JSONObject(String("key1"), new JSONValue(String("value1")));
    JSONObject *object2 = new JSONObject(String("key2"), new JSONValue(String("value2")));
    array->push(new JSONValue(object1));
    array->push(new JSONValue(object2));
    JSONValue *value = new JSONValue(array);

    JSONValue val = value->get("key2");
    val.print();

    REQUIRE(value->get("key2").equals(new JSONValue(String("value2"))));
}