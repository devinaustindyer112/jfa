#include "Parser.hpp"
#include "../JSON/JSONValue.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

Parser::Parser(JFA::String str)
{
    this->root = new JSONObject();
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

void Parser::parse(){
    // eat {
    // this->root = this->parseObject();
    // eat }
};

JSONValue *Parser::parseValue()
{
    // Parse object
    // Parse array
    // Parse string
}

JSONObject *Parser::parseObject()
{
    // while next token is string
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