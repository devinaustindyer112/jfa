#include "Parser.hpp"
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"

Parser::Parser(String str)
{
    this->tokenizer = Tokenizer(str);
    this->root = nullptr;
}

JSONNode Parser::parse()
{
    JSONNode node;
    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::LBRACE)
    {
        node.type = JSONNode::Type::OBJECT;
        node.children = this->parseObject();
    }
    else if (token.type == JSONToken::Type::LBRACKET)
    {
        node.type = JSONNode::Type::ARRAY;
        node.children = this->parseArray();
    }
    else
    {
        throw "Invalid JSON";
    }
    return node;
};

Array<JSONNode> Parser::parseObject()
{
    JSONNode node;
    JSONToken token = this->tokenizer.next();
    if (token.type == JSONToken::Type::STRING)
    {
        node.key = token.value;
        node.type = JSONNode::Type::OBJECT;
        this->eat(JSONToken::Type::COLON);
        token = this->tokenizer.next();
    }
    else
    {
        throw "Invalid JSON";
    }
    // Need to build an array from the children
};

void Parser::eat(JSONToken::Type type)
{
    JSONToken token = this->tokenizer.next();
    if (token.type != type)
    {
        throw "Invalid JSON";
    }
}
