#include "./parser.hpp"
#include "../jfa_string/jfa_string.hpp"
#include "../utils/utils.hpp"
#include "../../catch_amalgamated.hpp"

TEST_CASE("parse - simple object")
{
    Parser parser = Parser("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
    JSONObject obj = parser.parseObject();
    JSONValue effect = obj.entries.get("effect");
    REQUIRE(effect.string == "waves");
    REQUIRE(!(effect.string == "pulse"));

    JSONValue speed = obj.entries.get("speed");
    REQUIRE(speed.string == "0.5");
    REQUIRE(!(speed.string == "0.6"));

    Parser parserError = Parser("{ \"effect\": \"waves\",}");
    JSONObject objError = parserError.parseObject();
    JSONValue effectError = objError.entries.get("effect");
    REQUIRE(effectError.string == "wavess");
}
