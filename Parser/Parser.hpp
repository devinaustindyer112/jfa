#ifndef PARSE_HPP
#define PARSE_HPP
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"

struct JSONNode
{
    enum class Type
    {
        OBJECT,
        ARRAY,
        STRING,
        NUMBER,
        BOOLEAN,
        NULL,
    };
    JSONNode::Type type;
    String key;
    Array<JSONNode> children;
};

class Parser
{
private:
    Tokenizer tokenizer;
    JSONNode *root;

    Array<JSONNode> parseObject();
    Array<JSONNode> parseArray();
    void eat(JSONToken::Type type);

public:
    Parser(String str);
    JSONNode parse();
};

#endif // PARSE_HPP