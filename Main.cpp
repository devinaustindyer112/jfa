// #include "Parser/Parser.hpp"
#include "JSON/JSONObject.hpp"
#include "JSON/JSONValue.hpp"
#include "catch_amalgamated.hpp"
#include <iostream>

int main()
{
    JSONValue test = JSONValue(new JSONObject("foo", JSONValue("bar")));
    JSONObject obj2 = JSONObject("foo", JSONValue(new JSONObject("ban", JSONValue(new JSONObject("baz", JSONValue("buz"))))));
    obj2.print();
    return 0;
}
