#include "Parser.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

Parser::Parser(String str)
{
    this->root = JSONObject();
    this->tokenizer = Tokenizer(str);
}

Parser::~Parser()
{
    // traverse and call delete on all new'd objects
}

void Parser::parse()
{
    this->root.key = "root";
    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::LBRACE)
    {
        this->root.value = JSONValue(this->parseObject());
    }
    else
    {
        throw "Invalid JSON";
    }
};

JSONObject *Parser::parseObject()
{
    JSONObject *object = new JSONObject();
    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::STRING)
    {
        object->key = token.value;
    }
    else
    {
        throw "Invalid JSON";
    }

    this->eat(JSONToken::Type::COLON);
    token = this->tokenizer.next();

    if (token.type == JSONToken::Type::STRING)
    {
        object->value = JSONValue(token.value);
    }
    else if (token.type == JSONToken::Type::LBRACE)
    {
        object->value = JSONValue(this->parseObject());
    }
    else
    {
        throw "Invalid JSON";
    }

    return object;
}

Array<JSONValue> Parser::parseArray()
{
    return Array<JSONValue>();
};

void Parser::eat(JSONToken::Type type)
{
    JSONToken token = this->tokenizer.next();
    if (token.type != type)
    {
        throw "Invalid JSON";
    }
}

void Parser::print()
{
    this->root.print();
}