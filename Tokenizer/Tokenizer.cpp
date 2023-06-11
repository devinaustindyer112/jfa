#include "Tokenizer.hpp"
#include "../String/String.hpp"

Tokenizer::Tokenizer(String str)
{
    this->str = str;
    this->index = 0;
}

JSONToken Tokenizer::next()
{
    if (this->index >= this->str.length())
    {
        throw "No more tokens";
    }
    JSONToken token;
    char c = this->str[this->index];
    if (c == '{')
    {
        this->index++;
        token.type = JSONToken::Type::LBRACE;
        token.value = c;
    }
    else if (c == '}')
    {
        this->index++;
        token.type = JSONToken::Type::RBRACE;
        token.value = c;
    }
    else if (c == '[')
    {
        this->index++;
        token.type = JSONToken::Type::LBRACKET;
        token.value = c;
    }
    else if (c == ']')
    {
        this->index++;
        token.type = JSONToken::Type::RBRACKET;
        token.value = c;
    }
    else if (c == ':')
    {
        this->index++;
        token.type = JSONToken::Type::COLON;
        token.value = c;
    }
    else if (c == ',')
    {
        this->index++;
        token.type = JSONToken::Type::COMMA;
        token.value = c;
    }
    else if (c == '"')
    {
        this->index++;
        String str = "";
        while (this->index < this->str.length())
        {
            char c = this->str[this->index];
            if (c == '"')
            {
                this->index++;
                break;
            }
            else
            {
                str = str + c;
                this->index++;
            }
        }
        token.type = JSONToken::Type::STRING;
        token.value = str;
    }
    return token;
}