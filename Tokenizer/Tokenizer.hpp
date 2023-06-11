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
    Tokenizer(String str);
    ~Tokenizer();
    JSONToken next();
    bool hasNext();
};