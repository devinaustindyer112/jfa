#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include "../jfa_string/jfa_string.hpp"

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
    JFA::String value;
};

class Tokenizer
{
private:
    JFA::String str;
    JSONToken currentToken;
    JSONToken previousToken;
    int index;

public:
    Tokenizer();
    Tokenizer(JFA::String str);
    JSONToken next();
    bool hasNext();
    JSONToken previous();
};

#endif // TOKENIZER_HPP