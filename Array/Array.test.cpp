#include "Array.hpp"
#include "../catch_amalgamated.hpp"

template class Array<int>;

TEST_CASE("Array", "[Array]")
{
    Array<int> arr = Array<int>();

    REQUIRE(arr.length() == 0);
}

TEST_CASE("Push", "[Push]")
{
    Array<int> arr = Array<int>();

    arr.push(1);
    arr.push(2);
    arr.push(3);

    REQUIRE(arr.length() == 3);
}

TEST_CASE("Pop", "[Pop]")
{
    Array<int> arr = Array<int>();

    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.pop();

    REQUIRE(arr.length() == 2);
}

TEST_CASE("Index", "[Index]")
{
    Array<int> arr = Array<int>();

    arr.push(1);
    arr.push(2);
    arr.push(3);

    REQUIRE(arr[2] == 3);
}