#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("constructors", "[array]")
{
    Array<int> array1 = Array<int>();
    REQUIRE(array1.length() == 0);

    array1.push(1);
    array1.push(2);
    array1.push(3);
    Array<int> array2 = array1;
    REQUIRE(array2.length() == 3);
}

TEST_CASE("push", "[array]")
{
    Array<int> array1 = Array<int>();
    array1.push(1);
    array1.push(2);
    array1.push(3);
    REQUIRE(array1.length() == 3);
}

TEST_CASE("pop", "[array]")
{
    Array<int> array1 = Array<int>();
    array1.push(1);
    array1.push(2);
    array1.push(3);
    REQUIRE(array1.length() == 3);

    int popped = array1.pop();
    REQUIRE(popped == 3);
    REQUIRE(array1.length() == 2);
}

TEST_CASE("get", "[array]")
{
    Array<int> array1 = Array<int>();
    array1.push(1);
    array1.push(2);
    array1.push(3);
    REQUIRE(array1.length() == 3);

    int element = array1.get(1);
    REQUIRE(element == 2);
}

TEST_CASE("operator==", "[array]")
{
    Array<int> array1 = Array<int>();
    array1.push(1);
    array1.push(2);

    Array<int> array2 = Array<int>();
    array2.push(1);
    array2.push(2);

    REQUIRE(array1 == array2);
}