#include "Tokenizer.hpp"
#include "../catch_amalgamated.hpp"

TEST_CASE("next", "[next]")
{
    Tokenizer tokenizer = Tokenizer("{1, 2, 3, 4}");

    REQUIRE(tokenizer.next().type == JSONToken::Type::LBRACE);
}