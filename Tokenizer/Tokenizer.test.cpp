#include "Tokenizer.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("next", "[next]")
{
    Tokenizer tokenizer = Tokenizer("\"Yo\"");

    JSONToken token = tokenizer.next();
    REQUIRE(token.type == JSONToken::Type::STRING);
    REQUIRE(token.value == "Yo");
    REQUIRE(token.value.equals("Yo"));
}