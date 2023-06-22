#ifndef PARSE_HPP
#define PARSE_HPP
#include "../String/String.hpp"
#include "../Tokenizer/Tokenizer.hpp"
#include "../Array/Array.hpp"
#include <iostream>

struct JSONObject;

struct JSONValue
{
    enum class Type
    {
        OBJECT,
        ARRAY,
        STRING,
    };

    Type type;
    String string;
    JSONObject *object;

    ~JSONValue()
    {
        std::cout << "JSONValue deleted" << std::endl;
    }
};

struct JSONObject
{
    String key;
    JSONValue *value;

    ~JSONObject()
    {
        std::cout << "JSONObject deleted" << std::endl;
    }
};

class Parser
{
private:
    Tokenizer tokenizer;
    JSONObject *root;
    Array<JSONObject *> *objects;
    Array<JSONValue *> *values;

    JSONObject *parseObject();
    Array<JSONValue> parseArray();

    void eat(JSONToken::Type type);

public:
    Parser(String str);
    ~Parser();
    void parse();
    String print();
};

#endif // PARSE_HPP