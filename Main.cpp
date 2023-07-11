// #include "Parser/Parser.hpp"
#include "JSON/JSONObject.hpp"
#include "JSON/JSONValue.hpp"
#include "catch_amalgamated.hpp"
#include <iostream>

int main()
{
    // create objects different ways then see which constructor is called.
    // use std::cout to print
    JSONValue test = JSONValue(new JSONObject("foo", JSONValue("bar")));
    JSONObject obj2 = JSONObject("foo", JSONValue(new JSONObject("ban", JSONValue(new JSONObject("baz", JSONValue("buz"))))));
    obj2.print();
    return 0;
}
