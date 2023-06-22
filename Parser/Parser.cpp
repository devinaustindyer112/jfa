#include "Parser.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

Parser::Parser(String str)
{
    this->root = new JSONObject();
    this->tokenizer = Tokenizer(str);
    this->objects = new Array<JSONObject *>();
    this->values = new Array<JSONValue *>();
}

Parser::~Parser()
{
    delete this->root;
    for (int i = 0; i < this->objects->length(); i++)
    {
        delete (*this->objects)[i];
    }

    for (int i = 0; i < this->values->length(); i++)
    {
        delete (*this->values)[i];
    }
}

void Parser::parse()
{
    this->root->key = "root";
    JSONValue *value = new JSONValue();
    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::LBRACE)
    {
        value->type = JSONValue::Type::OBJECT;
        value->object = this->parseObject();
    }
    // else if (token.type == JSONToken::Type::LBRACKET)
    // {
    //     value->type = JSONValue::Type::ARRAY;
    //     value->elements = this->parseArray();
    // }
    else
    {
        throw "Invalid JSON";
    }
    this->values->push(value);
    this->root->value = value;
};

JSONObject *Parser::parseObject()
{
    JSONObject *object = new JSONObject();
    JSONValue *value = new JSONValue();
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
        value->type = JSONValue::Type::STRING;
        value->string = token.value;
    }
    else if (token.type == JSONToken::Type::LBRACE)
    {
        value->type = JSONValue::Type::OBJECT;
        value->object = this->parseObject();
    }
    // else if (token.type == JSONToken::Type::LBRACKET)
    // {
    //     value->type = JSONValue::Type::ARRAY;
    //     value->elements = this->parseArray();
    // }
    else
    {
        throw "Invalid JSON";
    }

    object->value = value;
    this->objects->push(object);
    this->values->push(value);
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
    String key = this->root->value->object->key;
    String value = this->root->value->object->value->string;
    std::cout << key.toCharArray() << std::endl;
    std::cout << value.toCharArray() << std::endl;

    return "";
}