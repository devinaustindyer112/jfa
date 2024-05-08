#include "tokenizer.hpp"
#include "../jfa_string/jfa_string.hpp"

Tokenizer::Tokenizer()
{
    this->str = "";
    this->index = 0;

    this->previousToken.type = JSONToken::Type::STRING;
    this->previousToken.value = "";

    this->currentToken.type = JSONToken::Type::STRING;
    this->currentToken.value = "";
}

Tokenizer::Tokenizer(JFA::String str)
{
    this->str = str.replaceAll(" ", "");
    this->index = 0;

    this->previousToken.type = JSONToken::Type::STRING;
    this->previousToken.value = "";

    this->currentToken.type = JSONToken::Type::STRING;
    this->currentToken.value = "";
}

JSONToken Tokenizer::next()
{
    this->previousToken = this->currentToken;

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
        JFA::String str = "";
        this->index++;
        while (this->index < this->str.length())
        {
            c = this->str[this->index];
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

    this->currentToken = token;
    return token;
}

bool Tokenizer::hasNext()
{
    return this->index < this->str.length();
}

JSONToken Tokenizer::previous()
{
    return this->previousToken;
}