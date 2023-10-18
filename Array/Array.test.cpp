#include "Array.hpp"
#include "../String/String.hpp"
#include "../JSON/JSONValue.hpp"
#include "../JSON/JSONObject.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("constructors", "[array]")
{
    // Array<int> array1 = Array<int>();
    // REQUIRE(array1.length() == 0);

    // array1.push(1);
    // array1.push(2);
    // array1.push(3);
    // Array<int> array2 = array1;
    // REQUIRE(array2.length() == 3);

    // Working
    Array<JFA::String> array3 = Array<JFA::String>();
    array3.push(JFA::String("Hello"));

    // Not working
    Array<JSONValue> array4 = Array<JSONValue>();
    array4.push(JSONValue("Hello"));
    REQUIRE(array3.length() == 1);
}
