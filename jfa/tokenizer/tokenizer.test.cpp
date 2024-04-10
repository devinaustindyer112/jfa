#include "tokenizer.hpp"
#include "../../catch_amalgamated.hpp"

TEST_CASE("constructor")
{
    Tokenizer tokenizer = Tokenizer("{ \"effect\": \"waves\", \"speed\": \"0.5\", \"color\": \"blue\" }");
}