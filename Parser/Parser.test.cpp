#include "./Parser.hpp"
#include "../String/String.hpp"
#include "../Utilities/Utilities.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("parse - simple object")
{
    Parser parser = Parser("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
    JSONObject object = parser.parseObject();
    REQUIRE(!(object.get("effect") == JSONValue("wavess")));
    REQUIRE((object.get("effect") == JSONValue("waves")));
    REQUIRE(!(object.get("speed") == JSONValue("0.6")));
    REQUIRE((object.get("speed") == JSONValue("0.5")));

    JSONValue value = object.get("speed");
    std::cout << value.string.str;
}
