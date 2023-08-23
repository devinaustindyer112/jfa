#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

template class Array<String>;

//=============================
// Keep updating the JSONValue and JSONObject classes
// So that all array tests pass.
// Need to work on memory management.
// ============================

// The tests below will all work, but only when we explicitly define an
// assignment operator (currently commented out).

// The problem is that the default assignment operator is creating
// two objects with references to the same thing being deleted/freed multiple times.
// Defining a proper assignment operator makes sure that the assignment operator
// creates entirely new references.

// Works because we never delete the obj1 or obj2.

TEST_CASE("Test1")
{
    Array<JSONObject> *arr1 = new Array<JSONObject>();
    Array<JSONObject> *arr2 = new Array<JSONObject>();

    JSONObject *obj1 = new JSONObject("foo", new JSONValue("bar"));
    JSONObject *obj2 = new JSONObject("bin", new JSONValue("baz"));

    arr1->push(obj1);
    arr1->push(obj2);

    // REQUIRE(!arr1->equals(arr2));
}

// It doesn't work because we do delete the obj1 or obj2.

// TEST_CASE("Test2")
// {
//     Array<JSONObject> *arr1 = new Array<JSONObject>();
//     Array<JSONObject> *arr2 = new Array<JSONObject>();

//     JSONObject *obj1 = new JSONObject("foo", new JSONValue("bar"));
//     JSONObject *obj2 = new JSONObject("bin", new JSONValue("baz"));

//     arr1->push(obj1);
//     arr1->push(obj2);

//     delete obj1;
//     delete obj2;

//     // REQUIRE(!arr1->equals(arr2));
// }

// This doesn't work because obj1 and obj2 go out of scope, causing a
// delete (we explicitly delete above. here implicitly)

// TEST_CASE("Test3")
// {
//     Array<JSONObject> *arr1 = new Array<JSONObject>();
//     Array<JSONObject> *arr2 = new Array<JSONObject>();

//     JSONObject obj1 = JSONObject("foo", new JSONValue("bar"));
//     JSONObject obj2 = JSONObject("bin", new JSONValue("baz"));

//     arr1->push(obj1);
//     arr1->push(obj2);

//     // REQUIRE(!arr1->equals(arr2));
// }
