#include "./Parser.hpp"
#include "../String/String.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("parse - simple object")
{
    Parser parser = Parser("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
    JSONObject object = parser.parseObject();
    REQUIRE(!(object.get("effect") == JSONValue("wavess")));
    REQUIRE((object.get("effect") == JSONValue("waves")));
}
