#include "Parser.hpp"
#include "../JSON/JSONValue.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

Parser::Parser(JFA::String str)
{
    this->root = JSONObject();
    this->tokenizer = Tokenizer(str);
    this->parse();
}

Parser::~Parser()
{
    // Need to implement this correctly

    // This broke everything
    // delete this->objects;
    // delete this->values;
}

void Parser::parse()
{
    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::STRING)
    {
        this->root = this->parseObject();
    }
    else
    {
        throw "Invalid JSON";
    }
};

JSONValue *Parser::parseValue()
{

    // if next token is string create object

    // Parse object
    // Parse array
    // Parse string
}

JSONObject *Parser::parseObject()
{
    JSONObject *object = new JSONObject();

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