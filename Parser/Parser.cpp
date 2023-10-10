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
    // Need to implement this correctly

    // This broke everything
    // delete this->objects;
    // delete this->values;
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
        throw "Invalid JSON - parseValue";
    }
    JSONValue value = JSONValue();
}

JSONObject Parser::parseObject()
{
    this->eat(JSONToken::Type::LBRACE);
    std::cout << "eat {" << std::endl;
    JSONObject object = JSONObject();

    // while next token is string
    while (this->tokenizer.hasNext())
    {
        std::cout << "has next" << std::endl;

        JSONToken token = this->tokenizer.next();
        if (token.type == JSONToken::Type::STRING)
        {
            JFA::String key = token.value;
            this->eat(JSONToken::Type::COLON);
            std::cout << "eat :" << std::endl;
            JSONValue value = this->parseValue();
            object.entries.put(key, value);
            std::cout << "token is string" << std::endl;
        }
        else if (token.type == JSONToken::Type::COMMA)
        {
            std::cout << "token is comma" << std::endl;
            continue;
        }
        else if (token.type == JSONToken::Type::RBRACE)
        {
            std::cout << "token is }" << std::endl;
            break;
        }
        else
        {
            throw "Invalid JSON - parseObject";
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
