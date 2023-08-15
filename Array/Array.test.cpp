#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

template class Array<String>;

TEST_CASE("Array", "[Array]")
{
    Array<String> arr = Array<String>();

    REQUIRE(arr.length() == 0);
}

TEST_CASE("Push", "[Push]")
{
    Array<String> arr = Array<String>();

    arr.push("1");
    arr.push("2");
    arr.push("3");

    REQUIRE(arr.length() == 3);
}

TEST_CASE("Pop", "[Pop]")
{
    Array<String> arr = Array<String>();

    arr.push("1");
    arr.push("2");
    arr.push("3");
    arr.pop();

    REQUIRE(arr.length() == 2);
}

TEST_CASE("Print", "[Print]")
{
    Array<String> arr = Array<String>();

    arr.push("1");
    arr.push("2");
    arr.push("3");

    arr.print();
}

TEST_CASE("Get", "[Get]")
{
    Array<String> *arr = new Array<String>();

    arr->push("1");
    arr->push("2");
    arr->push("3");

    String str = arr->get(0);
    REQUIRE(str == "1");
}

TEST_CASE("Print JSONValue", "[Print JSONValue]")
{
    Array<JSONValue> arr = Array<JSONValue>();

    arr.push(JSONValue("1"));
    arr.print();
    std::cout << std::endl;
}

TEST_CASE("Equals", "[Equals]")
{
    Array<String> *arr1 = new Array<String>();
    Array<String> *arr2 = new Array<String>();

    arr1->push("1");
    arr1->push("2");
    arr2->push("1");
    arr2->push("2");

    REQUIRE(arr1->equals(arr2));
}

TEST_CASE("Not equals", "[Not equals]")
{
    Array<JSONValue> *arr1 = new Array<JSONValue>();
    Array<JSONValue> *arr2 = new Array<JSONValue>();

    JSONValue val1 = JSONValue("1");
    JSONValue val2 = JSONValue("2");
    JSONValue val3 = JSONValue("3");

    arr1->push(val1);
    arr1->push(val2);
    arr2->push(val1);
    arr2->push(val3);

    REQUIRE(!arr1->equals(arr2));
}

TEST_CASE("Push pointer", "[Push pointer]")
{
    Array<JSONValue> *arr1 = new Array<JSONValue>();
    Array<JSONValue> *arr2 = new Array<JSONValue>();

    JSONValue *val1 = new JSONValue("1");
    JSONValue *val2 = new JSONValue("2");
    JSONValue *val3 = new JSONValue("2");

    arr1->push(val1);
    arr1->push(val2);
    arr2->push(val1);
    arr2->push(val3);

    REQUIRE(arr1->equals(arr2));
}

TEST_CASE("Copy constructor")
{
    Array<JSONValue> *arr1 = new Array<JSONValue>();
    arr1->push(JSONValue("1"));
    arr1->push(JSONValue("2"));
    Array<JSONValue> *arr2 = new Array<JSONValue>(arr1);
    REQUIRE(arr1->equals(arr2));
}