#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include "../String/String.hpp"

struct JSONToken
{
    enum class Type
    {
        LBRACE,
        RBRACE,
        LBRACKET,
        RBRACKET,
        COMMA,
        COLON,
        STRING,
    };
    JSONToken::Type type;
    String value;
};

class Tokenizer
{
private:
    String str;
    int index;

public:
    Tokenizer();
    Tokenizer(String str);
    JSONToken next();
    bool hasNext();
};

#endif // TOKENIZER_HPP