#include "tokenizer.hpp"
#include "../../catch_amalgamated.hpp"

TEST_CASE("constructor")
{
    Tokenizer tokenizer = Tokenizer("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
}

TEST_CASE("next")
{
    Tokenizer tokenizer = Tokenizer("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
    JSONToken next = tokenizer.next();
    REQUIRE(next.value == "{");
}

TEST_CASE("previous")
{
    Tokenizer tokenizer = Tokenizer("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
    tokenizer.next();
    tokenizer.next();
    JSONToken previous = tokenizer.previous();
    REQUIRE(previous.value == "{");
}