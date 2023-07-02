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
        this->root.value = JSONValue(JSONValue::Type::OBJECT, this->parseObject());
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
        object->value = JSONValue(JSONValue::Type::STRING, token.value);
    }
    else if (token.type == JSONToken::Type::LBRACE)
    {
        object->value = JSONValue(JSONValue::Type::OBJECT, this->parseObject());
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

String Parser::print()
{
    String key = this->root.value.object->key;
    String value = this->root.value.object->value.string;
    std::cout << key.toCharArray() << std::endl;
    std::cout << value.toCharArray() << std::endl;

    return "";
}