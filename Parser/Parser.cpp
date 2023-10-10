#include "Parser.hpp"
#include "../JSON/JSONValue.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

Parser::Parser(JFA::String str)
{
    this->tokenizer = Tokenizer(str);
}

Parser::~Parser()
{
}

JSONValue Parser::parseValue()
{

    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::STRING)
    {
        return JSONValue(token.value);
    }
    else
    {
        throw "Invalid JSON";
    }
    JSONValue value = JSONValue();
}

JSONObject Parser::parseObject()
{
    this->eat(JSONToken::Type::LBRACE);
    JSONObject object = JSONObject();

    // while next token is string
    while (this->tokenizer.hasNext())
    {
        JSONToken token = this->tokenizer.next();
        if (token.type == JSONToken::Type::STRING)
        {
            JFA::String key = token.value;
            this->eat(JSONToken::Type::COLON);
            JSONValue value = this->parseValue();
            object.entries.put(key, value);
        }
        else if (token.type == JSONToken::Type::COMMA)
        {
            continue;
        }
        else if (token.type == JSONToken::Type::RBRACE)
        {
            break;
        }
        else
        {
            throw "Invalid JSON";
        }
    }
    return object;
}

void Parser::eat(JSONToken::Type type)
{
    JSONToken token = this->tokenizer.next();
    if (token.type != type)
    {
        throw "Invalid JSON";
    }
}
