#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../catch_amalgamated.hpp"

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

TEST_CASE("Print JSONValue", "[Print JSONValue]")
{
    Array<JSONValue> arr = Array<JSONValue>();

    arr.push(JSONValue("1"));
    arr.print();
}
