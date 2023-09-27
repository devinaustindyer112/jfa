#include "Tokenizer.hpp"
#include "../catch_amalgamated.hpp"
#include <iostream>

TEST_CASE("constructor")
{
    Tokenizer tokenizer = Tokenizer(" { \"effect\":\"wave\" }  ");
    REQUIRE(tokenizer.hasNext());
    JSONToken token = tokenizer.next();
    REQUIRE(token.type == JSONToken::Type::LBRACE);
    REQUIRE(token.value == "{");
    REQUIRE(tokenizer.hasNext());
    token = tokenizer.next();
    REQUIRE(token.type == JSONToken::Type::STRING);
    REQUIRE(token.value == "effect");
    REQUIRE(tokenizer.hasNext());
    token = tokenizer.next();
    REQUIRE(token.type == JSONToken::Type::COLON);
    REQUIRE(token.value == ":");
    REQUIRE(tokenizer.hasNext());
    token = tokenizer.next();
    REQUIRE(token.type == JSONToken::Type::STRING);
    REQUIRE(token.value == "wave");
    REQUIRE(tokenizer.hasNext());
    token = tokenizer.next();
    REQUIRE(token.type == JSONToken::Type::RBRACE);
    REQUIRE(token.value == "}");
    REQUIRE(!tokenizer.hasNext());
}